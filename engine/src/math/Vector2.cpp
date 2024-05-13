#pragma once

#include "../../include/math/Vector2.hpp"
#include <cmath>

Vector2::Vector2() {
  this->x = 0;
  this->y = 0;
}

Vector2::Vector2(int x, int y) {
  this->x = x;
  this->y = y;
}

// float Vector2::get_x() const {
//   return this->x;
// }
//
// float Vector2::get_y() const {
//   return this->y;
// }

Vector2 Vector2::ZERO = Vector2();
Vector2 Vector2::E1 = Vector2(1, 0);
Vector2 Vector2::E2 = Vector2(0, 1);

std::ostream& operator<<(std::ostream& out, const Vector2& other) {
  return out << "Vector2(x: " << other.x << ", y: " << other.y << ")";
}

Vector2 Vector2::operator+(const Vector2& other) {
  Vector2 out(*this);
  out.x += other.x;
  out.y += other.y;
  return out;
}

Vector2 Vector2::operator-(const Vector2& other) {
  Vector2 out(*this);
  out.x -= other.x;
  out.y -= other.y;
  return out;
}

float Vector2::abs2() const {
  return pow(this->x, 2) + pow(this->y, 2);
}

float Vector2::abs() const {
  return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float Vector2::dot(const Vector2& other) const {
  Vector2 v(*this);
  return v.x * other.x + v.y * other.y;
}

float Vector2::angle_between(const Vector2& other) const {
  Vector2 out(*this);
  return acos(out.dot(other) / (out.abs() * other.abs()));
}

std::string to_string(const Vector2& out) {
  return "[" + std::to_string(out.x) + ", " + std::to_string(out.y) + "]";
} 

