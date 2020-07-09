#include "GroundMove.hpp"

using namespace godot;

void GroundMove::_register_methods() {
    register_method("_init", &GroundMove::_init);
    register_method("_ready", &GroundMove::_ready);
    register_method("_physics_process", &GroundMove::_physics_process);
}

GroundMove::GroundMove() {}

GroundMove::~GroundMove() {}

void GroundMove::_init() {}

void GroundMove::_ready() {
    Godot::print("Hello from Ground!");
}


void GroundMove::_physics_process(double delta) {}