#include "GameObject.h"

#include <iostream>
#include <algorithm>

GameObject::GameObject() : mComponents() {
  
}

GameObject::~GameObject() {
  // delete dynamically allocated components
  for(IComponent* c : mComponents){
    delete c;
    c = nullptr;
  }
}

/// @brief Add a component to this GameObject.
/// @param c The component to add.
void GameObject::add(IComponent* c) {
  if(c == nullptr) return;

  // do not add if the component is a GameObject
  if(c->getComponentType() == ComponentType::GameObject) {
    std::cout << "add: GameObjects cannot have GameObject components" << std::endl;
    return;
  }

  // only add if component of same type does not exist yet
  for(IComponent* component : mComponents) {
    // already exists; do not add
    if(component->getComponentType() == c->getComponentType()) {
      std::cout << "add: GameObject already has this component" << std::endl;
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
  else {
    std::cout << "remove: Could not find the component to remove" << std::endl;
  }
}

IComponent* GameObject::getComponentByType(ComponentType type) const
{
  IComponent* c = nullptr;

  // search components for matching component type
  for(IComponent* component : mComponents) {
    if(component != nullptr && component->getComponentType() == type) {
      c = component;
      break;
    }
  }

  return c;
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

/// @brief Retrieves this component's type.
/// @return The component's type.
IComponent::ComponentType GameObject::getComponentType() const
{
  return ComponentType::GameObject;
}
