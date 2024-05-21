#include <Renderable.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <math/Point.hpp>
#include <math/Vector2.hpp>

enum EntityState { VOID = 0, ALIVE = 1, DEAD = 2 };

class Player : public Renderable {
private:
  Point position;
  Vector2 direction;
  EntityState state;

public:
  Player();
  ~Player() = default;
  virtual ftxui::Component render(ftxui::ScreenInteractive screen) { 
    return ftxui::Component();
  }
};