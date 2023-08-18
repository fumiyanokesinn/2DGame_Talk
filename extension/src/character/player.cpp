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
}

Player::~Player() {}

void Player::_ready() {
  _animatedSprite2d = get_node<AnimatedSprite2D>(ANIMATED_SPRITE_2D_PATH);
}

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
  // 移動時のアニメーションとベクトル
  if (inputSingleton.is_key_pressed(KEY_RIGHT) &&
      !inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_UP) &&
      !inputSingleton.is_key_pressed(KEY_DOWN)) {
    direction = DIRECTION_RIGHT;
    velocity.x = 1 * speed;
    _animatedSprite2d->play("RightRun");
  }
  if (inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_RIGHT) &&
      !inputSingleton.is_key_pressed(KEY_UP) &&
      !inputSingleton.is_key_pressed(KEY_DOWN)) {
    direction = DIRECTION_LEFT;
    velocity.x = -1 * speed;
    _animatedSprite2d->play("LeftRun");
  }
  if (inputSingleton.is_key_pressed(KEY_UP) &&
      !inputSingleton.is_key_pressed(KEY_DOWN) &&
      !inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_RIGHT)) {
    direction = DIRECTION_BACK;
    velocity.y = -1 * speed;
    _animatedSprite2d->play("BackRun");
  }
  if (inputSingleton.is_key_pressed(KEY_DOWN) &&
      !inputSingleton.is_key_pressed(KEY_UP) &&
      !inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_RIGHT)) {
    direction = DIRECTION_FRONT;
    velocity.y = 1 * speed;
    _animatedSprite2d->play("FrontRun");
  }
  // 斜め移動
  if (inputSingleton.is_key_pressed(KEY_DOWN) &&
      inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_UP) &&
      !inputSingleton.is_key_pressed(KEY_RIGHT)) {
    velocity.y = 1 * speed;
    velocity.x = -1 * speed;
    if (direction == DIRECTION_BACK) {
      _animatedSprite2d->play("BackRun");
    } else if (direction == DIRECTION_LEFT) {
      _animatedSprite2d->play("LeftRun");
    }
  }
  if (inputSingleton.is_key_pressed(KEY_DOWN) &&
      inputSingleton.is_key_pressed(KEY_RIGHT) &&
      !inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_UP)) {
    velocity.y = 1 * speed;
    velocity.x = 1 * speed;
    if (direction == DIRECTION_BACK) {
      _animatedSprite2d->play("BackRun");
    } else if (direction == DIRECTION_RIGHT) {
      _animatedSprite2d->play("RightRun");
    }
  }
  if (inputSingleton.is_key_pressed(KEY_UP) &&
      inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_DOWN) &&
      !inputSingleton.is_key_pressed(KEY_RIGHT)) {
    velocity.y = -1 * speed;
    velocity.x = -1 * speed;
    if (direction == DIRECTION_FRONT) {
      _animatedSprite2d->play("FrontRun");
    } else if (direction == DIRECTION_LEFT) {
      _animatedSprite2d->play("LeftRun");
    }
  }
  if (inputSingleton.is_key_pressed(KEY_UP) &&
      inputSingleton.is_key_pressed(KEY_RIGHT) &&
      !inputSingleton.is_key_pressed(KEY_LEFT) &&
      !inputSingleton.is_key_pressed(KEY_DOWN)) {
    velocity.y = -1 * speed;
    velocity.x = 1 * speed;
    if (direction == DIRECTION_FRONT) {
      _animatedSprite2d->play("FrontRun");
    } else if (direction == DIRECTION_RIGHT) {
      _animatedSprite2d->play("RightRun");
    }
  }

  // 停止時のアニメーション
  if (velocity == Vector2(0.0f, 0.0f)) {
    if (direction == DIRECTION_LEFT) {
      _animatedSprite2d->play("LeftWeight");
    }
    if (direction == DIRECTION_RIGHT) {
      _animatedSprite2d->play("RightWeight");
    }
    if (direction == DIRECTION_BACK) {
      _animatedSprite2d->play("BackWeight");
    }
    if (direction == DIRECTION_FRONT) {
      _animatedSprite2d->play("FrontWeight");
    }
  }

  set_velocity(velocity * delta);
  move_and_slide();
}

#pragma clang diagnostic pop