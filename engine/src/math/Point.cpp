#pragma once

#include <math/Point.hpp> 

namespace rouge {

  Vector2 Point::to_vector() {
    return Vector2(this->x, this->y);
  }

  float Point::dist(const Point& q) {
    Point p(*this);
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
  }

  Vector2 position_vector(const Point& p, const Point& q) {
    return Vector2(p.x - q.x, p.y - q.y);
  }

  std::string to_string(const Point& p) {
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
  }

}