#include <filesystem>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "src/Context.cpp"
#include <math/Matrix.hpp>
#include "src/LevelSection.cpp"
#include "src/Player.cpp"

int main(int argc, char const* argv[]) {
  using namespace ftxui;

  auto screen = ScreenInteractive::TerminalOutput();

  Player p = Player();

  // LevelSection level = LevelSection();
  // std::cout << std::filesystem::current_path() << std::endl;
  // level.read_from_json("/home/agd/workspace/dev/cpp/rouge_engine/engine/src/levels/test.json");



  return EXIT_SUCCESS;
}
