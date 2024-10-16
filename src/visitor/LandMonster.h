#pragma once

#include "Monster.h"

class LandMonster : public Monster {
private:
  float mSprintMultiplier;
  bool mIsSprinting;
  float mSprintWarmup;
  float mSprintWarmupTimer;
  float mSprintDuration;
  float mSprintTimer;

public:
  LandMonster(float sprintMult);
  ~LandMonster();

  void accept(IVisitor& v) override;

  void sprint();
  void endSprint();

  void init() override;
  void execute(float deltaTime) override;
  void tearDown() override;
};