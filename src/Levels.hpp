#ifndef GODOTENGINE_LEVELS_HPP
#define GODOTENGINE_LEVELS_HPP

#include <Array.hpp>
#include <Vector2.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

class Levels {

    godot::Array Static_Scenes, Kinematic_Scenes, Rigid_Scenes;
    godot::Array levels_static_objects{}, levels_kinematic_objects{}, levels_rigid_objects{};
    godot::Array levels_static_objects_position{}, levels_kinematic_objects_position{};

    void add_static(int block_number, int x, int y);
    void add_kinematic(int block_number, int x, int y);

public:

    Levels() = default;

    void load_scenes();

    void load_level(int level_number, int width, int height);

    godot::Vector2 get_static_vector(int index);

    godot::Vector2 get_kinematic_vector(int index);

    godot::Ref <godot::PackedScene> get_static_object(int index);
    godot::Ref <godot::PackedScene> get_kinematic_object(int index);
    godot::Ref <godot::PackedScene> get_rigid_object(int index);

    int get_count_static();

    int kinematic_size();

};

#endif //GODOTENGINE_LEVELS_HPP