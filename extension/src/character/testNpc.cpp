#include "testNpc.h"

#include <godot_cpp/core/class_db.hpp>

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void TestNpc::_bind_methods() {}

TestNpc::TestNpc() {
  speed = 6000.0f;
  velocity = Vector2();
}

TestNpc::~TestNpc() {}

void TestNpc::_ready() {
  _animatedSprite2d = get_node<AnimatedSprite2D>(ANIMATED_SPRITE_2D_PATH);
}

void TestNpc::_physics_process(double delta) {
  _animatedSprite2d->play("Weight");
}

#pragma clang diagnostic pop