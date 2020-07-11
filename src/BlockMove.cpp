#include <String.hpp>
#include <InputEventScreenDrag.hpp>
#include <InputEventScreenTouch.hpp>

#include "BlocksManager.hpp"
#include "BlockMove.hpp"
#include "Constants.hpp"

using namespace godot;

void BlockMove::_register_methods() {
    register_method("_init", &BlockMove::_init);
    register_method("_input", &BlockMove::_input);
    register_method("_ready", &BlockMove::_ready);
    register_method("_physics_process", &BlockMove::_physics_process);
}

BlockMove::BlockMove() {}

BlockMove::~BlockMove() {}

void BlockMove::_init() {}

void BlockMove::_ready() {
    Godot::print("Hello from Block!");
    following_position = get_global_position();
}

void BlockMove::_input(InputEvent *input) {
    if (InputEventScreenTouch *input_touch = cast_to<InputEventScreenTouch>(input)) {
        switch(movement_phase) {
            case 0:
                if ((get_global_position() - input_touch->get_position()).length() < MOVE_RADIUS)
                    movement_phase++;
                break;
            case 1:
                movement_phase++;
                (cast_to<BlocksManager>(get_parent()->get_parent()))->remove_kinematic();
                break;
        }
    }
    if (InputEventScreenDrag *input_drag = cast_to<InputEventScreenDrag>(input)) {
        if (movement_phase == 1)
            following_position = input_drag->get_position();
    }
}

void BlockMove::_physics_process(double delta) {
    falling_line += GRAVITY * delta;
    if (following_position.y < falling_line) {
        following_position.y = falling_line;
    }
    move_and_slide((following_position - get_global_position()) * 20, Vector2(0, 0), false, 4, PI/4.0, false);
}