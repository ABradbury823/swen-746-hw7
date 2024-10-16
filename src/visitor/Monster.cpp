#include "Monster.h"

Monster::Monster() {
  mHealthComponent = new HealthComponent(10.0f);
  mMoveComponent = new MoveComponent(5.0f);
  mAttackComponent = new AttackComponent(1.0f, 0.5f);

  add(mHealthComponent);
  add(mMoveComponent);
  add(mAttackComponent);
}

Monster::~Monster() {
  
}

void Monster::init() {
  GameObject::init();
  std::cout << "Running Monster's init..." << std::endl;
}

void Monster::execute(float deltaTime) {
  GameObject::execute(deltaTime);
  std::cout << "Running Monster's execute..." << std::endl;
}

void Monster::tearDown() {
  GameObject::tearDown();
}