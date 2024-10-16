#pragma once

#include "../composite/GameObject.h"
#include "../composite/HealthComponent.h"
#include "../composite/MoveComponent.h"
#include "../composite/AttackComponent.h"
#include "IVisitor.h"

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

  virtual void accept(IVisitor& v) = 0;

  virtual void init() override;                   // runs once at start
  virtual void execute(float deltaTime) override; // runs every frame
  virtual void tearDown() override;               // runs once at end
};