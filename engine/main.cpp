#include <ftxui/dom/elements.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "src/math/Vector2.cpp"

int main(int argc, char const* argv[]) {
  using namespace ftxui;

  Vector2 v = Vector2(3.0, 3.0);
  int val = 50;  

  auto buttons = Container::Horizontal({
    Button("Decrease", [&] { v.x = v.x - 1; }, ButtonOption::Animated(Color::Red)),
    Button("Increase", [&] { v.x = v.x + 1; }, ButtonOption::Animated(Color::Green))
  }); 
  
  auto component = Renderer(buttons, [&] {
    return vbox({
      vbox({
            text("value = " + to_string(v)),
            separator(),
            gauge(v.abs() * 0.01f),
          }) | border,
      buttons->Render(),
      });
  });
  
  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(component);

  return EXIT_SUCCESS;
}
