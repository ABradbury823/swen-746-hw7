#pragma once

#include "LandMonster.h"
#include "AirMonster.h"

class IVisitor {
public:
  virtual ~IVisitor() {}

  virtual void visitLandMonster(LandMonster* m) = 0;
  virtual void visitAirMonster(AirMonster* m) = 0;
  //virtual void visitWaterMonster() = 0;
};