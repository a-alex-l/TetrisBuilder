#include <String.hpp>
#include <KinematicBody2D.hpp>
#include <BlocksManager.hpp>
#include "StrikeOutCollision.hpp"

using namespace godot;

void StrikeOutCollision::_register_methods() {
    register_method("_init", &StrikeOutCollision::_init);
    register_method("_ready", &StrikeOutCollision::_ready);
    register_method("_on_Trigger_body_entered", &StrikeOutCollision::_on_Trigger_body_entered);
}

StrikeOutCollision::StrikeOutCollision() {}

StrikeOutCollision::~StrikeOutCollision() {}

void StrikeOutCollision::_init() {}

void StrikeOutCollision::_on_Trigger_body_entered(Variant body) {
    Godot::print(cast_to<KinematicBody2D>(body)->___get_class_name());
    if (cast_to<KinematicBody2D>(body)) {
        Godot::print("Fall KinematicBody2D!");
        (cast_to<BlocksManager>(((Node2D*)body)->get_parent()->get_parent()))->remove_kinematic();
    } else {
        count_fallen_blocks++;
        Godot::print("Fall RigidBody2D!");
        get_parent()->remove_child(((Node2D *) body)->get_parent());
    }
}

void StrikeOutCollision::_ready() {
    Godot::print("Hello from StrikeOut!");
}

int StrikeOutCollision::get_count_fallen_blocks() {
    return count_fallen_blocks;
}
