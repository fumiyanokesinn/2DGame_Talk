#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

using namespace godot;

class Player : public CharacterBody2D {
  GDCLASS(Player, CharacterBody2D)

  const NodePath ANIMATED_SPRITE_2D_PATH = NodePath("AnimatedSprite2D");
  const String DIRECTION_LEFT = "LEFT";
  const String DIRECTION_RIGHT = "RIGHT";
  const String DIRECTION_FRONT = "FRONT";
  const String DIRECTION_BACK = "BACK";

  Vector2 velocity;
  float speed;

 private:
  AnimatedSprite2D* _animatedSprite2d;

  String direction = DIRECTION_RIGHT;

 protected:
  static void _bind_methods();

 public:
  Player();
  ~Player();

  void _ready();
  void _physics_process(double delta);
  void playerMove(double delta);
};

#endif
