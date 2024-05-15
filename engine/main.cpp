#include <ftxui/dom/elements.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "src/Context.cpp"

int main(int argc, char const* argv[]) {
  using namespace ftxui; 

  Context ctx = Context({"hey"});
  
  std::cout << ctx.print() << std::endl;

  return EXIT_SUCCESS;
}
