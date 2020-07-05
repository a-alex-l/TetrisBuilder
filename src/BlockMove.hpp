#ifndef GODOTENGINE_BLOCKDMOVE_HPP
#define GODOTENGINE_BLOCKDMOVE_HPP

#include <Godot.hpp>
#include <GodotGlobal.hpp>
#include <String.hpp>
#include <KinematicBody2D.hpp>
#include <InputEvent.hpp>
#include <InputEventScreenDrag.hpp>
#include <InputEventScreenTouch.hpp>

namespace godot {

    class BlockMove : public KinematicBody2D {
        GODOT_CLASS(BlockMove, KinematicBody2D)

        double falling_line = 0;
        Vector2 following_position;

    public:
        static void _register_methods();

        BlockMove();
        ~BlockMove();

        void _init(); // our initializer called by Godot

        void _input(InputEvent *input);

        void _physics_process(double delta);

        void hello();
    };

}

#endif //GODOTENGINE_BLOCKDMOVE_HPP
