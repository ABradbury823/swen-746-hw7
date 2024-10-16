#pragma once

#include "Component.h"

class AttackComponent : public Component {
private:
  float mDamage;
  bool mCanAttack;

  float mTimeBetweenAttacks;
  float mAttackTimer;

public: 
  AttackComponent(float damage, float attackSpeed); // ctor
  ~AttackComponent();                               // dtor

  /// @brief Retrieves damage dealt per attack.
  /// @return Damage
  inline float getDamage() const { return mDamage; }

  void attack();      // make attack once per attack time

  void init() override;                             // run once at start
  void execute(float deltaTime) override;           // run once per frame
  ComponentType getComponentType() const override;  // return = Attack
};