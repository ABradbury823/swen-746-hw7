#include "LandMonster.h"

LandMonster::LandMonster(float sprintMult) : mSprintMultiplier(sprintMult),
mIsSprinting(false), mSprintWarmup(.5f), mSprintWarmupTimer(0.0f),
mSprintDuration(.25f), mSprintTimer(0.0f) {

}

LandMonster::~LandMonster() {

}

void LandMonster::accept(IVisitor& v) {
  v.visitLandMonster(*this);
}

void LandMonster::sprint() {
  std::cout << "The Land Monster sprints!" << std::endl;
  MoveComponent* move = getMoveComponent();
  move->setMoveSpeedMult(mSprintMultiplier);
  mIsSprinting = true;
  mSprintTimer = 0.0f;
}

void LandMonster::endSprint() {
  std::cout << "The Land Monster returns to running." << std::endl;
  MoveComponent* move = getMoveComponent();
  move->setMoveSpeedMult(1.0f);
  mIsSprinting = false;
  mSprintWarmupTimer = 0.0f;
}

void LandMonster::init() {
  Monster::init();
  std::cout << "Running Land Monster's init..." << std::endl;

  endSprint();
}

void LandMonster::execute(float deltaTime) {
  Monster::execute(deltaTime);
  std::cout << "Running Land Monster's execute..." << std::endl;

  if(mIsSprinting) {
    if(mSprintTimer < mSprintDuration) {
      mSprintTimer += deltaTime;
    }
    else {
      // end sprint
      endSprint();
    }
  }
  else {
    if(mSprintWarmupTimer < mSprintWarmup) {
      mSprintWarmupTimer += deltaTime;
    }
    else {
      // start sprint
      sprint();
    }
  }

  
}

void LandMonster::tearDown() {
  Monster::tearDown();
}