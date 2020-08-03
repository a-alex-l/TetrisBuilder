#include <String.hpp>
#include <RigidBody2D.hpp>
#include <Camera2D.hpp>

#include "StrikeOutCollision.hpp"
#include "BlocksManager.hpp"
#include "GroundMove.hpp"
#include "BlockMove.hpp"
#include "Constants.hpp"

using namespace godot;

void BlocksManager::_register_methods() {
    register_method("_init", &BlocksManager::_init);
    register_method("_ready", &BlocksManager::_ready);
    register_method("_create_level", &BlocksManager::_create_level);
    register_method("_physics_process", &BlocksManager::_physics_process);
    register_method("remove_kinematic", &BlocksManager::remove_kinematic);
    register_method("add_kinematic", &BlocksManager::add_kinematic);
    register_method("get_count_of_remaining_blocks", &BlocksManager::get_count_of_remaining_blocks);
    register_method("get_count_fallen_blocks", &BlocksManager::get_count_fallen_blocks);
    register_method("get_score_now", &BlocksManager::get_score_now);
    register_method("turn_kinematic_left", &BlocksManager::turn_kinematic_left);
    register_method("turn_kinematic_right", &BlocksManager::turn_kinematic_right);
    register_method("is_game_end", &BlocksManager::is_game_end);
}

BlocksManager::BlocksManager() {}

BlocksManager::~BlocksManager() {
    Godot::print("Bye from Manager!");
}

void BlocksManager::_init() {}

void BlocksManager::_ready() {
    Godot::print("Hello from Manager!");
    level.load_scenes();
}

void BlocksManager::_create_level(int level_number) {
    level.load_level(level_number);
    Level_KinematicBody = (Node2D*)(level.get_level_object()->instance());
    Level_KinematicBody->set_name("Level");
    Level_KinematicBody->set_position(Vector2(WIDTH / 2, HEIGHT));
    add_child(Level_KinematicBody);
    add_kinematic();
}

void BlocksManager::remove_kinematic() {
    Node2D *tmp = (Node2D*)(level.get_rigid_object(number_kinematic_now)->instance());
    cast_to<RigidBody2D>(tmp->get_child(0))->set_transform(cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->get_transform());
    tmp->set_name(Block_KinematicBody_Now->get_name());
    remove_child(Block_KinematicBody_Now);
    add_child(tmp);
    if (number_kinematic_now + 1 == level.get_kinematic_size() || number_kinematic_now % 10 == 9)
        quake();
    if (number_kinematic_now + 1 != level.get_kinematic_size())
        add_kinematic();
    else
        game_end();
    find_height();
}

void BlocksManager::_physics_process(double delta) {
    static double time_pass = 2;
    if (get_count_fallen_blocks() == 5)
        game_end();
    if (game_end_blocks) {
        time_pass -= delta;
        if (time_pass < 0) {
            int last_tower_height = tower_height;
            find_height();
            time_pass = 1;
            if (last_tower_height == tower_height) {
                cast_to<Camera2D>(get_child(1))->set_position(Vector2(WIDTH / 2, HEIGHT / 2));
                game_end_show = true;
            }
        }
    }
}

void BlocksManager::add_kinematic() {
    number_kinematic_now++;
    Block_KinematicBody_Now = cast_to<Node2D>(level.get_kinematic_object(number_kinematic_now)->instance());
    Block_KinematicBody_Now->set_name(String("BLock ") + String::num_int64(number_kinematic_now));
    cast_to<Node2D>(Block_KinematicBody_Now->get_child(0))->set_position(Vector2(WIDTH / 2, tower_height - HEIGHT * 0.8));
    add_child(Block_KinematicBody_Now);
}

void BlocksManager::quake() {
    for (int i = 0; i < Level_KinematicBody->get_child_count(); i++)
        cast_to<GroundMove>((Level_KinematicBody->get_child(i))->get_child(0))->quake(i);
}

static int max(int a, int b) {
    return a > b ? a : b;
}


void BlocksManager::find_height() {
    tower_height = 1000;
    for (int i = max(2, int(get_child_count()) - 10); i + 1 < get_child_count(); i++) {
        if (tower_height > cast_to<Node2D>((get_child(i))->get_child(0))->get_global_position().y)
            tower_height = cast_to<Node2D>((get_child(i))->get_child(0))->get_global_position().y;
    }
}

int BlocksManager::get_count_of_remaining_blocks() {
    return level.get_kinematic_size() - number_kinematic_now - 1;
}

int BlocksManager::get_count_fallen_blocks() {
    return cast_to<StrikeOutCollision>(get_child(0))->get_count_fallen_blocks();
}

double BlocksManager::get_score_now() {
    double score = 100;
    return score * pow(1.01, number_kinematic_now) * pow(0.5, get_count_fallen_blocks());
}

void BlocksManager::turn_kinematic_left() {
    cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->rotate(-M_PI * 0.5);
}

void BlocksManager::turn_kinematic_right() {
    cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->rotate(M_PI * 0.5);
}

bool BlocksManager::is_game_end() {
    return game_end_show;
}

void BlocksManager::game_end() {
    find_height();
    if (double(-1 * tower_height + HEIGHT) / double(HEIGHT) > 1)
        cast_to<Camera2D>(get_child(1))->set_zoom(
            Vector2(double(-1 * tower_height + HEIGHT * 2) / double(HEIGHT),
                    double(-1 * tower_height + HEIGHT * 2) / double(HEIGHT)));
    Godot::print(String::num_real(double(HEIGHT) / double(-1 * tower_height + HEIGHT)));
    cast_to<Camera2D>(get_child(1))->set_position(Vector2(WIDTH / 2, tower_height / 2 + HEIGHT / 2));
    game_end_blocks = true;
}
