#ifndef GODOTENGINE_STRIKEOUTCOLLISION_HPP
#define GODOTENGINE_STRIKEOUTCOLLISION_HPP

#include <Godot.hpp>
#include <Area2D.hpp>

namespace godot {

    class StrikeOutCollision : public Area2D {
        GODOT_CLASS(StrikeOutCollision, Area2D)

    private:
    public:
        static void _register_methods();

        StrikeOutCollision();
        ~StrikeOutCollision();

        void _init();

        void _on_Trigger_body_entered(Variant body);

        void _ready();

    };

};

#endif //GODOTENGINE_STRIKEOUTCOLLISION_HPP
