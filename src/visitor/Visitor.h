#pragma once

class Visitor {
public:
  virtual void visitLandMonster() = 0;
  virtual void visitAirMonster() = 0;
  virtual void visitWaterMonster() = 0;
};