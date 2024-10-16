#include "MoveComponent.h"

MoveComponent::MoveComponent(float moveSpeed) :
mMoveSpeed(moveSpeed), mMoveSpeedMultiplier(1.0f),
mPosition(Vector()), mMoveDir(Vector::RightVector) {
  
}

MoveComponent::~MoveComponent() {

}

/// @brief Updates the move speed multiplier. Clamps to 0.0.
/// @param speedMult New speed multiplier
void MoveComponent::setMoveSpeedMult(float speedMult) {
  if(speedMult < 0.0f) {
    speedMult = 0.0f;
  }

  mMoveSpeedMultiplier = speedMult;
}

/// @brief Move to a new position.
/// @param newPos Desired position
void MoveComponent::move(Vector newPos) {
  mPosition = newPos;
  std::cout << "  New position: " << mPosition.toString() << std::endl;
}

/// @brief Run once at start.
void MoveComponent::init() {
  std::cout << "Running Move Component's init..." << std::endl;
}

/// @brief Run once per frame.
/// @param deltaTime Time since last execution, in seconds.
void MoveComponent::execute(float deltaTime) {
  std::cout << "Running Move Component's execute..." << std::endl;
  Vector newPos = mPosition + (mMoveDir * mMoveSpeed * mMoveSpeedMultiplier * deltaTime);
  move(newPos);
}

/// @brief Get component's type.
/// @return Component Type = Move
IComponent::ComponentType MoveComponent::getComponentType() const {
  return ComponentType::Move;
}