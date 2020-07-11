#ifndef GODOTENGINE_LEVELS_HPP
#define GODOTENGINE_LEVELS_HPP

#include <Array.hpp>
#include <Vector2.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

class Levels {

    godot::Array Static_Scenes, Kinematic_Scenes, Rigid_Scenes;
    godot::Ref <godot::PackedScene> level_scene;

    int level_number;
    int count_kinematic_blocks[10] = {5, 7, 10, 15, 25, 35, 40, 50, 60, 70};

public:

    Levels() = default;

    void load_scenes();

    void load_level(int level_number);

    godot::Ref <godot::PackedScene> get_level_object();
    godot::Ref <godot::PackedScene> get_kinematic_object(int index);
    godot::Ref <godot::PackedScene> get_rigid_object(int index);

    int get_count_static();

    int kinematic_size();

};

#endif //GODOTENGINE_LEVELS_HPP