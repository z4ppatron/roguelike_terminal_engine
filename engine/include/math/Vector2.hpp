#pragma once

// 2D vector class with integer entries.
#include <cmath>
#include <iostream>
#include <string>

namespace rouge {

struct Vector2 {
  int x;
  int y;

  ~Vector2();
  Vector2();
  Vector2(int x, int y);

  static Vector2 ZERO;
  static Vector2 E1;
  static Vector2 E2;

  Vector2 operator+(Vector2 const &other);
  Vector2 operator-(Vector2 const &other);

  float angle() const;
  float abs() const;
  float abs2() const;
  float dot(const Vector2 &other) const;
  float angle_between(const Vector2 &other) const;

  friend std::ostream &operator<<(std::ostream &out, const Vector2 &other);
  friend std::string to_string(const Vector2 &out);
};

std::string to_string(const Vector2 &out);
std::ostream &operator<<(std::ostream &out, const Vector2 &v);

}