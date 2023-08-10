// © Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community
// (CC-BY 3.0)
#ifndef SPRITE2D_H
#define SPRITE2D_H

// We don't need windows.h in this plugin but many others do and it throws up on
// itself all the time So best to include it and make sure CI warns us when we
// use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/sprite2d.hpp>

using namespace godot;

class GDE_Sprite2D : public Sprite2D {
  GDCLASS(GDE_Sprite2D, Sprite2D);

 private:
  double time_passed;

 protected:
  static void _bind_methods();

 public:
  GDE_Sprite2D();
  ~GDE_Sprite2D();

  void _process(double delta);
};

#endif