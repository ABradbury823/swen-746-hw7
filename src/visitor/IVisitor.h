#pragma once

// forward declare; avoid circular dependency with Monster
class LandMonster;
class AirMonster;

class IVisitor {
public:
  virtual ~IVisitor() {}

  virtual void visitLandMonster(LandMonster& m) = 0;
  virtual void visitAirMonster(AirMonster& m) = 0;
  //virtual void visitWaterMonster() = 0;
};