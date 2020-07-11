#include <Godot.hpp>

#include "Levels.hpp"

using namespace godot;

void Levels::load_scenes() {
    ResourceLoader *scenes_loader = ResourceLoader::get_singleton();

    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 0 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 1 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 2 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 3 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 4 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 5 KinematicBody.tscn"));
    Kinematic_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 6 KinematicBody.tscn"));

    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 0 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 1 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 2 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 3 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 4 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 5 RigidBody.tscn"));
    Rigid_Scenes.push_back(scenes_loader->load("res://scenes/blocks/Block 6 RigidBody.tscn"));
}

Ref <PackedScene> Levels::get_level_object() {
    return level_scene;
}

static int hash(int index) { return 9 * index * index % 7; }

Ref <PackedScene> Levels::get_kinematic_object(int index) {
    return Kinematic_Scenes[hash(index)];
}

Ref <PackedScene> Levels::get_rigid_object(int index) {
    return Rigid_Scenes[hash(index)];
}

int Levels::kinematic_size() {
    return count_kinematic_blocks[level_number];
}

void Levels::load_level(int level_number) {
    this->level_number = level_number;
    ResourceLoader *scenes_loader = ResourceLoader::get_singleton();
    level_scene = scenes_loader->load(String("res://scenes/levels/Level ") + String::num_int64(level_number) + String(".tscn"));
}