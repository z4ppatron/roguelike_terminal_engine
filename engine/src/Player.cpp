#include "math/Vector2.hpp"
#include <Player.hpp>

Player::Player() {
    this->set_display('o');
    this->set_layer(Layer::THINGS);
    this->set_status(true);
    this->position = Point(0, 0);
    this->direction = Vector2(0, 0);
    this->state = EntityState::ALIVE;
}