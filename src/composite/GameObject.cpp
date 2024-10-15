#include "GameObject.h"

#include <iostream>
#include <algorithm>

GameObject::GameObject() : mComponents() {
  
}

GameObject::~GameObject() {
  // delete dynamically allocated components
  for(IComponent* c : mComponents){
    delete c;
  }
}

/// @brief Add a component to this GameObject.
/// @param c The component to add.
void GameObject::add(IComponent* c) {
  if(c == nullptr) return;

  // only add if component of same type does not exist yet
  for(IComponent* component : mComponents) {
    // already exists; do not add
    if(component->getComponentType() == c->getComponentType()) {
      return;
    } 
  }

  mComponents.push_back(c);
}

/// @brief Remove a component from this GameObject.
/// @param c The component to remove.
void GameObject::remove(IComponent* c) {
  if(c == nullptr) return;

  auto it = std::remove(mComponents.begin(), mComponents.end(), c);

  if(it != mComponents.end()) {
    // erase from new end to actual end
    mComponents.erase(it, mComponents.end());
  }
}

/// @brief Function that runs once when component is first initialized.
void GameObject::init()
{
  std::cout << "Running GameObject's init..." << std::endl;
  
  for(IComponent* c : mComponents) {
    if(c) {
      c->init();
    }
  }

}

/// @brief Function that runs every frame.
void GameObject::execute() {
  std::cout << "Running GameObject's execute..." << std::endl;

  for(IComponent* c : mComponents) {
    if(c) {
      c->execute();
    }
  }
}

IComponent::ComponentType GameObject::getComponentType() const
{
  return ComponentType::GameObject;
}
