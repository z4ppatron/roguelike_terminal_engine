#include "../../include/math/Vector2.hpp"

Vector2::Vector2() {
  this->x = 0;
  this->y = 0;
}

Vector2::Vector2(int x, int y) {
  this->x = x;
  this->y = y;
}

int Vector2::get_x() const {
  return this->x;
}

int Vector2::get_y() const {
  return this->y;
}

Vector2 Vector2::ZERO = Vector2();
Vector2 Vector2::E1 = Vector2(1, 0);
Vector2 Vector2::E2 = Vector2(0, 1);

std::ostream& operator<<(std::ostream& out, const Vector2& v) {
  return out << "Vector2(x: " << v.x << ", y: " << v.y << ")";
}

Vector2 Vector2::operator+(const Vector2& v) {
  auto out = this;
  out->x += v.x;
  out->y += v.y;
  return *out;
}


