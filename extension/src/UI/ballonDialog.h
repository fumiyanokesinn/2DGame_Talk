#ifndef BALLON_DIALOG_H
#define BALLON_DIALOG_H

#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/classes/label.hpp>

using namespace godot;

class BallonDialog : public CanvasLayer {
  GDCLASS(BallonDialog, CanvasLayer)

  const NodePath NAME_PATH =
      NodePath("NinePatchRect/MarginContainer/VBoxContainer/Name");

 private:
  Label* _name;

 protected:
  static void _bind_methods();

 public:
  BallonDialog();
  ~BallonDialog();

  void _ready();

  void display();

  void testChat();
};

#endif
