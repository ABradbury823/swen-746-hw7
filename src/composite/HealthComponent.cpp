#include "HealthComponent.h"

#include <iostream>

HealthComponent::HealthComponent(float maxHealth): 
mMaxHealth(maxHealth), mHealth(0.0f), mIsAlive(true) {

}

HealthComponent::~HealthComponent() {

}

/// @brief Increase current hit points. Clamps to max health.
/// @param amount Amount to increase by.
void HealthComponent::restoreHealth(float amount) {
  if(amount < 0.0f) return;

  mHealth += amount;
  if(mHealth > mMaxHealth) {
    mHealth = mMaxHealth;
  }
}

/// @brief Decrease current hit points. Die when reaching 0.
/// @param amount Amount to decrease by.
void HealthComponent::takeDamage(float amount) {
  if(amount < 0.0f) return;

  mHealth -= amount;
  if(mHealth < 0.0f){
    mHealth = 0.0f;
    die();
  }
}

/// @brief GameObject owner has died.
void HealthComponent::die() {
  std::cout << "This GameObject has died." << std::endl;
  mIsAlive = false;
}

/// @brief Run once at start.
void HealthComponent::init() {
  std::cout << "Running Health Component's init..." << std::endl;
  mHealth = mMaxHealth;
}

/// @brief Run once per frame.
/// @param deltaTime Time since last execution, in seconds.
void HealthComponent::execute(float deltaTime) {
  std::cout << "Running Health Component's execute..." << std::endl;
}

/// @brief Get this component's type.
/// @return ComponentType = Health
IComponent::ComponentType HealthComponent::getComponentType() const {
  return ComponentType::Health;
}
