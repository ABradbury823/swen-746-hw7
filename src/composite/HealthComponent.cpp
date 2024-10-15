#include "HealthComponent.h"

#include <iostream>

HealthComponent::HealthComponent(float maxHealth): 
mMaxHealth(maxHealth), mHealth(0.0f), mIsAlive(true) {

}

HealthComponent::~HealthComponent() {

}

void HealthComponent::restoreHealth(float amount) {
  if(amount < 0.0f) return;

  mHealth += amount;
  if(mHealth > mMaxHealth) {
    mHealth = mMaxHealth;
  }
}

void HealthComponent::takeDamage(float amount) {
  if(amount < 0.0f) return;

  mHealth -= amount;
  if(mHealth < 0.0f){
    mHealth = 0.0f;
    die();
  }
}

void HealthComponent::die() {
  std::cout << "This GameObject has died." << std::endl;
  mIsAlive = false;
}

void HealthComponent::init() {
  std::cout << "Running Health Component's init..." << std::endl;
  mHealth = mMaxHealth;
}

void HealthComponent::execute(float deltaTime) {
  std::cout << "Running Health Component's execute..." << std::endl;
}

IComponent::ComponentType HealthComponent::getComponentType() const {
  return ComponentType::Health;
}
