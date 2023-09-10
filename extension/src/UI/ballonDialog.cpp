#include "ballonDialog.h"

#include <fstream>
#include <godot_cpp/core/class_db.hpp>
#include <nlohmann/json.hpp>

using namespace godot;
using json = nlohmann::json;

void BallonDialog::_bind_methods() {}

BallonDialog::BallonDialog() {}

BallonDialog::~BallonDialog() {}

void BallonDialog::_ready() {}

void BallonDialog::testChat() {
  std::ifstream f("extension\src\text\test.json");
  json data = json::parse(f);
}

// 表示をONにする
void BallonDialog::display() { set_visible(true); }