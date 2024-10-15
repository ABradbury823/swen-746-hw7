#include "MoveComponent.h"

MoveComponent::MoveComponent(float moveSpeed) :
mMoveSpeed(moveSpeed), mPosition(Vector()), mMoveDir(Vector::RightVector) {
  
}

MoveComponent::~MoveComponent() {

}

void MoveComponent::move(Vector newPos) {
  mPosition = newPos;
  std::cout << "  New position: " << mPosition.toString() << std::endl;
}

void MoveComponent::init() {
  std::cout << "Running Move Component's init..." << std::endl;
}

void MoveComponent::execute(float deltaTime) {
  std::cout << "Running Move Component's execute..." << std::endl;
  Vector newPos = mPosition + (mMoveDir * mMoveSpeed * deltaTime);
  move(newPos);
}

IComponent::ComponentType MoveComponent::getComponentType() const {
  return ComponentType::Move;
}