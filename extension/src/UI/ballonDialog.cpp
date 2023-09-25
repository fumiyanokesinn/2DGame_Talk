#include "ballonDialog.h"

#include <fstream>
#include <godot_cpp/core/class_db.hpp>
#include <nlohmann/json.hpp>

using namespace godot;
using json = nlohmann::json;

void BallonDialog::_bind_methods() {}

BallonDialog::BallonDialog() {}

BallonDialog::~BallonDialog() {}

void BallonDialog::_ready() {
  _name = get_node<Label>(NAME_PATH);
  testChat();
}

void BallonDialog::testChat() {
  std::ifstream jsonFile("test.json");

  if (!jsonFile.is_open()) {
    std::cerr << "The JSON file could not be opened." << std::endl;
    return;
  }

  // JSONデータをパースします
  nlohmann::json jsonData;
  jsonFile >> jsonData;

  // JSONデータを操作したり、値を取得したりできます
  std::string name = jsonData["name"];
  // std::string name = j["test"]["name"];
  // "name"の値を出力
  std::cout << "name: " << std::endl;
  // _name->set_text(name);
}

// 表示をONにする
void BallonDialog::display() { set_visible(true); }