#include "EvolutionVisitor.h"

#include <iostream>

EvolutionVisitor::EvolutionVisitor() {

}

EvolutionVisitor::~EvolutionVisitor() {

}

void EvolutionVisitor::visitLandMonster(LandMonster* m) {
  std::cout << "Look, I'm in a Land Monster!" << std::endl;
  float health = m->getHealthComponent()->getHealth();
  std::cout << "Here's it's health: " << health << std::endl;
  std::cout << "Let's rough it up a little." << std::endl;
  m->getHealthComponent()->takeDamage(5.0);
  health = m->getHealthComponent()->getHealth();
  std::cout << "Here's it's health: " << health << std::endl;
  std::cout << "Okay, let's patch you up" << std::endl;
  m->getHealthComponent()->restoreHealth(5.0);
  std::cout << "Here's it's health: " << health << std::endl;
}

void EvolutionVisitor::visitAirMonster(AirMonster* m) {
  std::cout << "Look, I'm in an Air Monster!" << std::endl;
  float health = m->getHealthComponent()->getHealth();
  std::cout << "Here's it's health: " << health << std::endl;
  std::cout << "Let's rough it up a little." << std::endl;
  m->getHealthComponent()->takeDamage(1.0);
  health = m->getHealthComponent()->getHealth();
  std::cout << "Here's it's health: " << health << std::endl;
  std::cout << "Okay, let's patch you up" << std::endl;
  m->getHealthComponent()->restoreHealth(11.0);
  std::cout << "Here's it's health: " << health << std::endl;
}