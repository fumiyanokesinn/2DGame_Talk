#ifndef TEST_NPC_H
#define TEST_NPC_H

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
using namespace godot;

class TestNpc : public CharacterBody2D {
  GDCLASS(TestNpc, CharacterBody2D)

  const NodePath ANIMATED_SPRITE_2D_PATH = NodePath("AnimatedSprite2D");

  Vector2 velocity;
  float speed;

 private:
  AnimatedSprite2D* _animatedSprite2d;

 protected:
  static void _bind_methods();

 public:
  TestNpc();
  ~TestNpc();

  void _ready();
  void _physics_process(double delta);
};

#endif
