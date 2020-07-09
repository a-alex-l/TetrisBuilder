#ifndef GODOTENGINE_GROUNDMOVE_HPP
#define GODOTENGINE_GROUNDMOVE_HPP

#include <Godot.hpp>
#include <String.hpp>
#include <KinematicBody2D.hpp>
#include <InputEvent.hpp>
#include <InputEventScreenDrag.hpp>
#include <InputEventScreenTouch.hpp>

namespace godot {

    class GroundMove : public KinematicBody2D {
        GODOT_CLASS(GroundMove, KinematicBody2D)

    private:

    public:
        static void _register_methods();

        GroundMove();
        ~GroundMove();

        void _init();

        void _ready();

        void _physics_process(double delta);

    };

};

#endif //GODOTENGINE_GROUNDMOVE_HPP
