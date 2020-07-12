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
}

BlocksManager::BlocksManager() {}

BlocksManager::~BlocksManager() {}

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
    Godot::print("Static done!");
    add_kinematic();
}

void BlocksManager::remove_kinematic() {
    Node2D *tmp = (Node2D*)(level.get_rigid_object(number_kinematic_now)->instance());
    cast_to<RigidBody2D>(tmp->get_child(0))->set_global_transform(cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->get_global_transform());
    tmp->set_name(Block_KinematicBody_Now->get_name());
    remove_child(Block_KinematicBody_Now);
    add_child(tmp);
    if (number_kinematic_now + 1 == level.get_kinematic_size() || number_kinematic_now % 10 == 9)
        quake();
    if (number_kinematic_now + 1 != level.get_kinematic_size())
        add_kinematic();
}

void BlocksManager::_physics_process(double delta) {}

void BlocksManager::add_kinematic() {
    number_kinematic_now++;
    Block_KinematicBody_Now = cast_to<Node2D>(level.get_kinematic_object(number_kinematic_now)->instance());
    Block_KinematicBody_Now->set_name(String("BLock ") + String::num_int64(number_kinematic_now));
    Block_KinematicBody_Now->set_position(Vector2(WIDTH / 2, HEIGHT / 20));
    add_child(Block_KinematicBody_Now);
}

void BlocksManager::quake() {
    Godot::print("Heeey!");
    for (int i = 0; i < Level_KinematicBody->get_child_count(); i++) {
        cast_to<GroundMove>((Level_KinematicBody->get_child(i))->get_child(0))->quake(i);
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
    return score * pow(1.01, get_count_of_remaining_blocks()) * pow(0.5, get_count_fallen_blocks());
}

void BlocksManager::turn_kinematic_left() {
    cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->rotate(90);
}

void BlocksManager::turn_kinematic_right() {
    cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->rotate(-90);
}