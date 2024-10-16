#pragma once

#include "Monster.h"

class AirMonster : public Monster {
private:
  float mFlightTime;
  float mFlightTimer;
  bool mIsFlying;
  float mRoostTime;
  float mRoostTimer;

public:
  AirMonster(float flightTime, float roostTime);
  ~AirMonster();

  void accept(IVisitor* v);

  void fly();

  void roost();

  void init() override;
  void execute(float deltaTime) override;
  void tearDown() override;
};