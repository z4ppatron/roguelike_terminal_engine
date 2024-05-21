#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

enum Layer { BG = 0, THINGS = 1, FG = 2 };

class Renderable {
protected:
  char display;
  bool status;
  Layer layer;

public:
  char get_display() { return display; }
  bool get_status() { return status; }
  unsigned get_layer() { return layer; }

  void set_display(char c) { display = c; }
  void set_status(bool b) { status = b; }
  void flip_status() { status = !status; }
  void set_layer(Layer l) { layer = l; }

  virtual ftxui::Component render();
};