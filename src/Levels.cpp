#include <Godot.hpp>

#include "Levels.hpp"

using namespace godot;

void Levels::load_scenes() {
    ResourceLoader *scenes_loader = ResourceLoader::get_singleton();

    Static_Scenes.push_back(scenes_loader->load("res://scenes/Stony Ground.tscn"));

    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/Block 0 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/Block 1 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/Block 2 KinematicBody.tscn"));

    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/Block 0 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/Block 1 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/Block 2 RigidBody.tscn"));
}

void Levels::add_static(int block_number, int x, int y) {
    levels_static_objects.push_back(Static_Scenes[block_number]);
    levels_static_objects_position.push_back(Vector2(x, y));
}

void Levels::add_kinematic(int block_number, int x, int y) {
    levels_kinematic_objects.push_back(Kinematic_Scenes[block_number]);
    levels_rigid_objects.push_back(Rigid_Scenes[block_number]);
    levels_kinematic_objects_position.push_back(Vector2(x, y));
}

Vector2 Levels::get_static_vector(int index) {
    return levels_static_objects_position[index];
}

Vector2 Levels::get_kinematic_vector(int index) {
    return levels_kinematic_objects_position[index];
}

Ref <PackedScene> Levels::get_static_object(int index) {
    return levels_static_objects[index];
}

Ref <PackedScene> Levels::get_kinematic_object(int index) {
    return levels_kinematic_objects[index];
}

Ref <PackedScene> Levels::get_rigid_object(int index) {
    return levels_rigid_objects[index];
}

int Levels::get_count_static() {
    return levels_static_objects.size();
}

int Levels::kinematic_size() {
    return levels_kinematic_objects.size();
}

void Levels::load_level(int level_number, int width, int height) {
    levels_static_objects.clear(), levels_kinematic_objects.clear(), levels_rigid_objects.clear();
    levels_static_objects_position.clear(), levels_kinematic_objects_position.clear();
    switch(level_number) {
        case 0:
            add_static(0, width * 0.5, height * 1.2);
            add_kinematic(1, width * 0.5, height * 0.1);
            add_kinematic(0, width * 0.5, height * 0.1);
            add_kinematic(1, width * 0.5, height * 0.1);
            add_kinematic(0, width * 0.5, height * 0.1);
            break;
        case 2:
            add_static(0, width * 0.5, height * 1.2);
            add_kinematic(1, width * 0.5, height * 0.1);
        case 3:
            add_static(0, width * 0.5, height * 1.2);
            add_kinematic(0, width * 0.5, height * 0.1);
    }
}