#pragma once

#include "Component.h"

class AttackComponent : public Component {
private:
  float mDamage;
  bool mCanAttack;

  float mTimeBetweenAttacks;
  float mAttackTimer;

public: 
  AttackComponent(float damage, float attackSpeed);
  ~AttackComponent();

  inline float getDamage() const { return mDamage; }

  void attack();

  void init() override;
  void execute(float deltaTime) override;
  ComponentType getComponentType() const override;
};