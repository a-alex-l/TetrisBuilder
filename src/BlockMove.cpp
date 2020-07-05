#include "BlockMove.hpp"
#include "Constants.hpp"

using namespace godot;

void BlockMove::_register_methods() {
    register_method("hello", &BlockMove::hello);
    register_method("_input", &BlockMove::_input);
    register_method("_init", &BlockMove::_init);
    register_method("_physics_process", &BlockMove::_physics_process);
}

BlockMove::BlockMove() {}

BlockMove::~BlockMove() {}

void BlockMove::_init() {
    following_position = get_global_position();
}

void BlockMove::_input(InputEvent *input) {
    if (InputEventScreenTouch *input_touch = cast_to<InputEventScreenTouch>(input)) {
        following_position = input_touch->get_position();
    }
    if (InputEventScreenDrag *input_drag = cast_to<InputEventScreenDrag>(input)) {
        following_position = input_drag->get_position();
    }
}

void BlockMove::_physics_process(double delta) {
    falling_line += gravity * delta;
    move_and_slide((following_position - get_global_position()) * 50);
    Godot::print(String::num_real(falling_line) + " " + String(get_global_position()));
}

void BlockMove::hello() {
    Godot::print("Hello world! From Block!");
}
