#include "player.h"

#include <godot_cpp/core/class_db.hpp>

#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void Player::_bind_methods() {}

Player::Player() {}

Player::~Player() {}

void Player::_physics_process(double delta) {
  // if (Input::get_singleton()->is_action_pressed("Move_Right")) {
  //   UtilityFunctions::print("HELLO");
  // }
}

/**
 * プレイヤーの操作
 */
void Player::_input(InputEvent *inputEvent) {
  bool isInputEventKey = inputEvent->is_class("InputEventKey");
  if (isInputEventKey) {
    if (inputEvent->is_action("Move_Right")) {
      UtilityFunctions::print("Move_Right");
    }
    if (inputEvent->is_action("Move_Left")) {
      UtilityFunctions::print("Move_Left");
    }
    if (inputEvent->is_action("Move_Up")) {
      UtilityFunctions::print("Move_Up");
    }
    if (inputEvent->is_action("Move_Down")) {
      UtilityFunctions::print("Move_Down");
    }
  }
}

#pragma clang diagnostic pop