#ifndef GODOTENGINE_GROUNDMOVE_HPP
#define GODOTENGINE_GROUNDMOVE_HPP

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot {

    class GroundMove : public KinematicBody2D {
        GODOT_CLASS(GroundMove, KinematicBody2D)

    private:

        godot::RandomNumberGenerator *rand = RandomNumberGenerator::_new();
        bool is_quake = false;
        double time_quake = 1;
        Vector2 position;

    public:
        static void _register_methods();

        GroundMove();
        ~GroundMove();

        void _init();

        void _ready();

        void _physics_process(double delta);

        void quake(int i);

    };

};

#endif //GODOTENGINE_GROUNDMOVE_HPP
