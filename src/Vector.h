#pragma once

#include <string>

class Vector {
public:
  float X;
  float Y;
  float Z;

  Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f) : X(x), Y(y), Z(z) {}

  Vector(const Vector& other) : X(other.X), Y(other.Y), Z(other.Z) {}

  Vector& operator=(const Vector& other);

  Vector operator+(const Vector& other);

  Vector operator-(const Vector& other);

  Vector operator*(float scalar);

  /// @brief Set position to a set of values.
  /// @param x X coord
  /// @param y Y coord
  /// @param z Z coord
  void setValues(float x, float y, float z);

  /// @brief Set vector to a new vector
  /// @param pos New position
  void setVector(const Vector& pos);

  /// @brief Stringifies values of this Vector.
  /// @return String representation of Vector. 
  std::string toString();

  static const Vector ZeroVector;
  static const Vector RightVector;
  static const Vector UpVector;
  static const Vector ForwardVector;
};