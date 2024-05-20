#include <ftxui/dom/elements.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "src/Context.cpp"
#include <math/Matrix.hpp>
#include "src/Level.cpp"

int main(int argc, char const* argv[]) {
  using namespace ftxui;

  Level level = Level();
  ifstream file("../engine/src/levels/test.txt");
  
  level.read_from_file(file);

  return EXIT_SUCCESS;
}
