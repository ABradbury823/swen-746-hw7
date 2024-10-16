#pragma once

#include "IVisitor.h"

class EvolutionVisitor : public IVisitor {
public:
  EvolutionVisitor();
  ~EvolutionVisitor();

  void visitLandMonster(LandMonster* m) override;
  void visitAirMonster(AirMonster* m) override;
};