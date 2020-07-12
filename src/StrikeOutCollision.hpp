#ifndef GODOTENGINE_STRIKEOUTCOLLISION_HPP
#define GODOTENGINE_STRIKEOUTCOLLISION_HPP

#include <Godot.hpp>
#include <Area2D.hpp>

namespace godot {

    class StrikeOutCollision : public Area2D {
        GODOT_CLASS(StrikeOutCollision, Area2D)

    private:

        int count_fallen_blocks = 0;

    public:
        static void _register_methods();

        StrikeOutCollision();
        ~StrikeOutCollision();

        void _init();

        void _ready();

        void _on_Trigger_body_entered(Variant body);

        int get_count_fallen_blocks();

    };

};

#endif //GODOTENGINE_STRIKEOUTCOLLISION_HPP
