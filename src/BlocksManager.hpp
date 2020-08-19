#ifndef GODOTENGINE_BLOCKSMANAGER_HPP
#define GODOTENGINE_BLOCKSMANAGER_HPP

#include <Godot.hpp>
#include <Node2D.hpp>

#include "Levels.hpp"

namespace godot {

    class BlocksManager : public Node2D {
        GODOT_CLASS(BlocksManager, Node2D)

    private:

        enum GamePhase {
            WAIT_GAME_START,
            START_GAME,
            WAIT_FOR_LEVEL,
            WAIT_FOR_FIRST_BLOCK,
            WAIT_FOR_NEXT_BLOCK,
            WAIT_FOR_SHOW_TOWER,
            WAIT_TO_NEXT_TOWER_CHECK,
            END_GAME
        };
        double current_timer = 0;
        GamePhase game_phase = WAIT_GAME_START;

        int number_kinematic_now = -1;
        Node2D *Block_KinematicBody_Now;
        Node2D *Level_KinematicBody;
        Levels level;

    public:
        static void _register_methods();

        BlocksManager();
        ~BlocksManager();

        void _init();
        void _ready();
        void _physics_process(double delta);

        void _create_level(int level_number);

        void remove_kinematic();
        void add_kinematic();

        void quake();

        int get_count_of_remaining_blocks();
        int get_count_fallen_blocks();
        double get_score_now();

        void turn_kinematic_left();
        void turn_kinematic_right();

        int find_height();
        bool is_tower_stay();

        bool is_game_end();
        void game_end();

    };

};


#endif //GODOTENGINE_BLOCKSMANAGER_HPP
