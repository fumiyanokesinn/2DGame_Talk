#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

using namespace godot;

class Player : public CharacterBody2D {
  GDCLASS(Player, CharacterBody2D)

  Vector2 velocity;
  float speed;
  NodePath animatedSprite2DPath = NodePath("AnimatedSprite2D");

 private:
  Sprite2D image;
  AnimatedSprite2D _animatedSprite2d;

 protected:
  static void _bind_methods();

 public:
  Player();
  ~Player();

  void _ready();
  void _physics_process(double delta);
  void _input(InputEvent *inputEvent);
};

#endif
