#include "MoveComponent.h"

#include <iostream>

MoveComponent::MoveComponent(float moveSpeed) :
mMoveSpeed(moveSpeed) {

}

MoveComponent::~MoveComponent() {

}

void MoveComponent::move(float deltaTime) {
  std::cout << "The GameObject moves to a new position!" << std::endl;
}

void MoveComponent::init() {
  std::cout << "Running Move Component's init..." << std::endl;
}

void MoveComponent::execute() {
  std::cout << "Running Move Component's execute..." << std::endl;
}

IComponent::ComponentType MoveComponent::getComponentType() const {
  return ComponentType::Move;
}