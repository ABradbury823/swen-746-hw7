#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::~GameObject() {
  
}

void GameObject::add(IComponent& c) {
  mComponents.push_back(c);
}

void GameObject::remove(IComponent& c) {
  auto it = std::find(mComponents.begin(), mComponents.end(), c);

  if(it != mComponents.end()) {
    mComponents.erase(it);
  }
}

/// @brief Function that runs once when component is first initialized.
void GameObject::init()
{
  for(IComponent& c : mComponents) {
    c.init();
  }
}

/// @brief Function that runs every frame.
void GameObject::execute() {
  for(IComponent& c : mComponents) {
    c.execute();
  }
}
