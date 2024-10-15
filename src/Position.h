#pragma once

#include <string>

class Position {
public:
  float X;
  float Y;
  float Z;

  Position(float x = 0.0f, float y = 0.0f, float z = 0.0f) : X(x), Y(y), Z(z) {}

  Position(const Position& other) : X(other.X), Y(other.Y), Z(other.Z) {}

  Position& operator=(const Position& other) {
    if(this != &other){
      X = other.X;
      Y = other.Y;
      Z = other.Z;
    }
    return *this;
  }

  /// @brief Set position to a set of values.
  /// @param x X coord
  /// @param y Y coord
  /// @param z Z coord
  void setPosition(float x, float y, float z) {
    X = x;
    Y = y;
    Z = z;
  }

  /// @brief Set position to a new position
  /// @param pos New position
  void setPosition(Position& pos) {
    X = pos.X;
    Y = pos.Y;
    Z = pos.Z;
  }

  /// @brief Stringifies values of this Position.
  /// @return String representation of Position. 
  std::string toString() {
    return "(" + std::to_string(X) +
    ", " + std::to_string(Y) + 
    ", " + std::to_string(Z) + ")";
  }
};