#pragma once

// Point struct.
#include "Vector2.hpp"
#include <string>

struct Point {
  int x;
  int y;

  ~Point();
  Vector2 to_vector();
  float dist(const Point &q);
};

Vector2 position_vector(const Point &p, const Point &q);
std::string to_string(const Point &p);
