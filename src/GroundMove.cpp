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
    position = get_global_position();
    Godot::print("Hello from Ground!");
}

void GroundMove::quake(int i) {
    is_quake = true;
    rand->set_seed(i);
}

void GroundMove::_physics_process(double delta) {
    if (is_quake) {
        time_quake -= delta;
        if (time_quake < 0) {
            time_quake = 1;
            is_quake = false;
            move_and_slide(position - get_global_position());
        }
        Vector2 tmp =  Vector2(rand->randf() * 8 - 4, rand->randf() * 8 - 4);
        move_and_slide((position - get_global_position() + tmp) * 4);
    }
}