#include "Vector.h"

#include <string>

Vector& Vector::operator=(const Vector& other) {
  if(this != &other){
    X = other.X;
    Y = other.Y;
    Z = other.Z;
  }
  return *this;
}

Vector Vector::operator+(const Vector& other) {
  return Vector(X + other.X, Y + other.Y, Z + other.Z);
}

Vector Vector::operator-(const Vector& other) {
  return Vector(X - other.X, Y - other.Y, Z - other.Z);
}

Vector Vector::operator*(float scalar) {
  return Vector(X * scalar, Y * scalar, Z * scalar);
}

/// @brief Set position to a set of values.
/// @param x X coord
/// @param y Y coord
/// @param z Z coord
void Vector::setValues(float x, float y, float z) {
  X = x;
  Y = y;
  Z = z;
}

/// @brief Set vector to a new vector
/// @param pos New position
void Vector::setVector(const Vector& pos) {
  X = pos.X;
  Y = pos.Y;
  Z = pos.Z;
}

/// @brief Stringifies values of this Vector.
/// @return String representation of Vector. 
std::string Vector::toString() {
  return "(" + std::to_string(X) +
  ", " + std::to_string(Y) + 
  ", " + std::to_string(Z) + ")";
}

const Vector Vector::ZeroVector(0.0f, 0.0f, 0.0f);
const Vector Vector::RightVector(1.0f, 0.0f, 0.0f);
const Vector Vector::UpVector(0.0f, 1.0f, 0.0f);
const Vector Vector::ForwardVector(0.0f, 0.0f, 1.0f);