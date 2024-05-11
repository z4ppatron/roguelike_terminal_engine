#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "math/Vector2.cpp"

int main(int argc, char const* argv[]) {
  using namespace ftxui;

  Element document = 
    hbox({
        text("left")   | border,
        text("middle") | border  | flex,
        text("right")  | border,
        });

  auto screen = Screen::Create(
      Dimension::Full(),
      Dimension::Fit(document)
      );
  Render(screen, document);
  screen.Print();
  
  Vector2 v = Vector2(3, 3);
  
  std::cout << v << std::endl;

  return EXIT_SUCCESS;
}
