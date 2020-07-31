#ifndef GODOTENGINE_BLOCKDMOVE_HPP
#define GODOTENGINE_BLOCKDMOVE_HPP

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <InputEvent.hpp>

namespace godot {

    class BlockMove : public KinematicBody2D {
        GODOT_CLASS(BlockMove, KinematicBody2D)

    private:

        int movement_phase = 0; // 0-nothing, 1-block move, 2-camera move
        double falling_line = 0;
        Vector2 following_position = Vector2(-239, -239);

    public:
        static void _register_methods();

        BlockMove();
        ~BlockMove();

        void _init();

        void _ready();

        void _input(InputEvent *input);

        void _physics_process(double delta);

    };

};

#endif //GODOTENGINE_BLOCKDMOVE_HPP
