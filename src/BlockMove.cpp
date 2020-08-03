#include <String.hpp>
#include <InputEventScreenDrag.hpp>
#include <InputEventScreenTouch.hpp>
#include <Camera2D.hpp>

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
    following_position = get_position();
    falling_line = get_position().y;
}

void BlockMove::_input(InputEvent *input) {
    if (InputEventScreenTouch *input_touch = cast_to<InputEventScreenTouch>(input)) {
        switch(movement_phase) {
            case 0:
                if ((get_position() - input_touch->get_position() -
                        cast_to<Camera2D>(get_parent()->get_parent()->get_child(1))->get_position()
                            + Vector2(WIDTH / 2, HEIGHT / 2)).length() < MOVE_RADIUS)
                    movement_phase = 1;
                else
                    movement_phase = 2;
                break;
            case 1:
                if (is_on_floor() || is_on_wall() || is_on_ceiling())
                    (cast_to<BlocksManager>(get_parent()->get_parent()))->remove_kinematic();
                movement_phase = 0;
                break;
            case 2:
                movement_phase = 0;
                break;
        }
    }
    if (InputEventScreenDrag *input_drag = cast_to<InputEventScreenDrag>(input)) {
        switch(movement_phase) {
            case 1:
                following_position = input_drag->get_position() + cast_to<Camera2D>(
                        get_parent()->get_parent()->get_child(1))->get_position() -
                                     Vector2(WIDTH / 2, HEIGHT / 2);
                break;
            case 2:
                cast_to<Camera2D>(get_parent()->get_parent()->get_child(1))->set_position(
                        cast_to<Camera2D>(
                                get_parent()->get_parent()->get_child(1))->get_position() -
                        input_drag->get_speed() / 20
                );
                break;
        }
    }
}

void BlockMove::_physics_process(double delta) {
    static double touch_time = 1;
    falling_line += GRAVITY * delta;
    if (following_position.y < falling_line) {
        if ((is_on_floor() || is_on_wall() || is_on_ceiling()) && movement_phase != 1) {
            touch_time -= delta;
            if (touch_time <= 0) {
                (cast_to<BlocksManager>(get_parent()->get_parent()))->remove_kinematic();
                return;
            }
        }
        following_position.y = falling_line;
    }
    move_and_slide((following_position - get_global_position()) * 20, Vector2(0, 0), false, 4, PI/4.0, false);
}