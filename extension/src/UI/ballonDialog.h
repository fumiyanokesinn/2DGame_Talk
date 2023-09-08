#ifndef BALLON_DIALOG_H
#define BALLON_DIALOG_H

#include <godot_cpp/classes/canvas_layer.hpp>

using namespace godot;

class BallonDialog : public CanvasLayer {
  GDCLASS(BallonDialog, CanvasLayer)

 protected:
  static void _bind_methods();

 public:
  BallonDialog();
  ~BallonDialog();

  void _ready();
};

#endif
