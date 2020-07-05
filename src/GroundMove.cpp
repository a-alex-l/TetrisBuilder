#include "GroundMove.hpp"

using namespace godot;

void GroundMove::_register_methods() {
    register_method("hello", &GroundMove::hello);
}

GroundMove::GroundMove() {}

GroundMove::~GroundMove() {}

void GroundMove::_init() {}

String GroundMove::hello() {
    String ans = "Hello world! From Ground!";
    return ans;
}
