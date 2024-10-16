#pragma once

#include "../composite/GameObject.h"
#include "../composite/HealthComponent.h"
#include "../composite/MoveComponent.h"
#include "../composite/AttackComponent.h"

class Monster : public GameObject {
private:
  HealthComponent* mHealthComponent;
  MoveComponent* mMoveComponent;
  AttackComponent* mAttackComponent;

public:
  Monster();
  virtual ~Monster();

  // get health component
  virtual inline HealthComponent* getHealthComponent() const final { return mHealthComponent; }
  // get move component
  virtual inline MoveComponent* getMoveComponent() const final { return mMoveComponent; }
  // get attack component
  virtual inline AttackComponent* getAttackComponent() const final { return mAttackComponent; }

  void init() override;                   // runs once at start
  void execute(float deltaTime) override; // runs every frame
  void tearDown() override;               // runs once at end
};