#include "AttackComponent.h"

AttackComponent::AttackComponent(float damage, float attackSpeed) : 
mDamage(damage), mCanAttack(true), 
mTimeBetweenAttacks(attackSpeed), mAttackTimer(0.0f) {

}

AttackComponent::~AttackComponent() {
  
}

void AttackComponent::attack() {
  std::cout << "  attack: The GameObject makes an attack for " << mDamage << " damage!" << std::endl;
  mCanAttack = false;
}

void AttackComponent::init() {
  std::cout << "Running Attack Component's init..." << std::endl;
}

void AttackComponent::execute(float deltaTime) {
  std::cout << "Running Attack Component's execute..." << std::endl;

  if(mAttackTimer < mTimeBetweenAttacks) {
    mAttackTimer += deltaTime;
  }
  else {
    mAttackTimer = 0.0f;
    mCanAttack = true;
  }

  if(mCanAttack) {
    attack();
  }
}

IComponent::ComponentType AttackComponent::getComponentType() const {
  return ComponentType::Attack;
}