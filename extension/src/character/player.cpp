#include "player.h"

#include <godot_cpp/core/class_db.hpp>

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void Player::_bind_methods() {}

Player::Player() {
  speed = 6000.0f;
  velocity = Vector2();
  image;
}

Player::~Player() {}

void Player::_ready() {}

void Player::_physics_process(double delta) { playerMove(delta); }

/**
 * プレイヤーの操作
 */
void Player::_input(InputEvent* inputEvent) {
  bool isInputEventKey = inputEvent->is_class("InputEventKey");
  // if (isInputEventKey) {
  //   if (inputEvent->is_action("Move_Right")) {
  //     UtilityFunctions::print("Move_Right");
  //   }
  //   if (inputEvent->is_action("Move_Left")) {
  //     UtilityFunctions::print("Move_Left");
  //   }
  //   if (inputEvent->is_action("Move_Up")) {
  //     UtilityFunctions::print("Move_Up");
  //   }
  //   if (inputEvent->is_action("Move_Down")) {
  //     UtilityFunctions::print("Move_Down");
  //   }
  // }
}

/**
 * プレイヤーの移動とアニメーション
 */
void Player::playerMove(double delta) {
  velocity = Vector2(0.0f, 0.0f);
  Input& inputSingleton = *Input::get_singleton();
  if (inputSingleton.is_key_pressed(KEY_RIGHT)) {
    direction = DIRECTION_RIGHT;
    velocity.x = 1 * speed;
    get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("RightRun");
  }
  if (inputSingleton.is_key_pressed(KEY_LEFT)) {
    direction = DIRECTION_LEFT;
    velocity.x = -1 * speed;
    get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("LeftRun");
  }
  if (inputSingleton.is_key_pressed(KEY_UP)) {
    direction = DIRECTION_BACK;
    velocity.y = -1 * speed;
    get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("BackRun");
  }
  if (inputSingleton.is_key_pressed(KEY_DOWN)) {
    direction = DIRECTION_FRONT;
    velocity.y = 1 * speed;
    get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("FrontRun");
  }

  if (velocity == Vector2(0.0f, 0.0f)) {
    if (direction == DIRECTION_LEFT) {
      get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("LeftWeight");
    }
    if (direction == DIRECTION_RIGHT) {
      get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("RightWeight");
    }
    if (direction == DIRECTION_BACK) {
      get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("BackWeight");
    }
    if (direction == DIRECTION_FRONT) {
      get_node<AnimatedSprite2D>(animatedSprite2DPath)->play("FrontWeight");
    }
  }

  set_velocity(velocity * delta);
  move_and_slide();
}

#pragma clang diagnostic pop