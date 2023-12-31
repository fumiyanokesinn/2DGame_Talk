#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "UI/ballonDialog.h"
#include "character/player.h"
#include "character/testNpc.h"
#include "sprite2d.h"
#include "summator.h"

using namespace godot;

void initialize_summator_types(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
  ClassDB::register_class<Summator>();
  ClassDB::register_class<GDE_Sprite2D>();
  ClassDB::register_class<Player>();
  ClassDB::register_class<TestNpc>();
  ClassDB::register_class<BallonDialog>();
}

void uninitialize_summator_types(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}

extern "C" {

// Initialization.

GDExtensionBool GDE_EXPORT
summator_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                      GDExtensionClassLibraryPtr p_library,
                      GDExtensionInitialization *r_initialization) {
  GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
                                          r_initialization);

  init_obj.register_initializer(initialize_summator_types);
  init_obj.register_terminator(uninitialize_summator_types);
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
}
}
