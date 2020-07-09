#include <String.hpp>
#include <RigidBody2D.hpp>

#include "BlocksManager.hpp"
#include "BlockMove.hpp"

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
    _create_level(0);
}

void BlocksManager::_create_level(int level_number) {
    level.load_level(level_number, get_viewport_rect().size.x, get_viewport_rect().size.y);
    for (int i = 0; i < level.get_count_static(); i++) {
        Node2D *tmp = (Node2D*)(level.get_static_object(i)->instance());
        tmp->set_name(String("BLock ") + String::num_real(i));
        tmp->set_position(level.get_static_vector(i));
        add_child(tmp);
    }
    Godot::print("Static done!");
    add_kinematic();
}

void BlocksManager::remove_kinematic() {
    Godot::print("Hey! Delete!" + String::num_real(number_kinematic_now));
    Node2D *tmp = (Node2D*)(level.get_rigid_object(number_kinematic_now)->instance());
    cast_to<RigidBody2D>(tmp->get_child(0))->set_global_transform(cast_to<BlockMove>(Block_KinematicBody_Now->get_child(0))->get_global_transform());
    tmp->set_name(Block_KinematicBody_Now->get_name());
    Godot::print(String("Kinem : ") + String(Block_KinematicBody_Now->get_global_position()));
    remove_child(Block_KinematicBody_Now);
    add_child(tmp);
    Godot::print(String("Rigid : ") + String(tmp->get_global_position()));
    add_kinematic();
    if (number_kinematic_now == level.kinematic_size()) {
        Godot::print("You win! Probably...");
    }
}

void BlocksManager::_physics_process(double delta) {}

void BlocksManager::add_kinematic() {
    number_kinematic_now++;
    Godot::print("Hey! Add Kinematic");
    Block_KinematicBody_Now = cast_to<Node2D>(level.get_kinematic_object(number_kinematic_now)->instance());
    Block_KinematicBody_Now->set_name(String("BLock ") + String::num_int64(number_kinematic_now));
    Block_KinematicBody_Now->set_position(level.get_kinematic_vector(number_kinematic_now));
    add_child(Block_KinematicBody_Now);
}