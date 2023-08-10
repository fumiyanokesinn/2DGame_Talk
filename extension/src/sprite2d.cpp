// © Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community
// (CC-BY 3.0)
#include "sprite2d.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

GDE_Sprite2D::GDE_Sprite2D() { time_passed = 0.0; }

GDE_Sprite2D::~GDE_Sprite2D() {}

void GDE_Sprite2D::_process(double delta) {
  time_passed += delta;
  Vector2 new_position = Vector2(100.0 + (10.0 * sin(time_passed * 2.0)),
                                 600.0 + (10.0 * cos(time_passed * 1.5)));
  set_position(new_position);
}

void GDE_Sprite2D::_bind_methods() {}