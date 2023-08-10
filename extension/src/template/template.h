// © Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community
// (CC-BY 3.0)
#ifndef TEMPLATE_H
#define TEMPLATE_H

// We don't need windows.h in this plugin but many others do and it throws up on
// itself all the time So best to include it and make sure CI warns us when we
// use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

class Template : public CharacterBody2D {
  GDCLASS(Template, CharacterBody2D);

 protected:
  static void _bind_methods();

 public:
  Template();
  ~Template();

  void _process(double delta);
};

#endif