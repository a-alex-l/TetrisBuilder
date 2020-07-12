#include <String.hpp>

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
    count_fallen_blocks++;
    get_parent()->remove_child(((Node2D*)body)->get_parent());
}

void StrikeOutCollision::_ready() {
    Godot::print("Hello from StrikeOut!");
}

int StrikeOutCollision::get_count_fallen_blocks() {
    return count_fallen_blocks;
}
