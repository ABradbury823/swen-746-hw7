#include "AirMonster.h"

AirMonster::AirMonster(float flightTime, float roostTime) : 
mFlightTime(flightTime), mFlightTimer(0.0f), mIsFlying(false), 
mRoostTime(roostTime), mRoostTimer(0.0f) {

}

AirMonster::~AirMonster() {

}

void AirMonster::accept(IVisitor& v) {
  v.visitAirMonster(*this);
}

void AirMonster::fly() {
  std::cout << "The Air Monster takes off!" << std::endl;
  MoveComponent* move = getMoveComponent();
  move->setMoveSpeedMult(3.0f);
  mIsFlying = true;
  mFlightTimer = 0.0f;
}

void AirMonster::roost() {
  std::cout << "The Air Monster lands to rest." << std::endl;
  MoveComponent* move = getMoveComponent();
  move->setMoveSpeedMult(0.0f);
  mIsFlying = false;
  mRoostTimer = 0.0f;
}

void AirMonster::init() {
  Monster::init();
  std::cout << "Running Air Monster's init..." << std::endl;

  roost();
}

void AirMonster::execute(float deltaTime) {
  Monster::execute(deltaTime);
  std::cout << "Running Air Monster's execute..." << std::endl;

  if(mIsFlying) {
    if(mFlightTimer < mFlightTime) {
      mFlightTimer += deltaTime;
    }
    else {
      // end flying
      roost();
    }
  }
  else {
    if(mRoostTimer < mRoostTime) {
      mRoostTimer += deltaTime;
    }
    else {
      // start flying
      fly();
    }
  }

  
}

void AirMonster::tearDown() {
  Monster::tearDown();
}