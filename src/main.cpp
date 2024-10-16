#include "composite/GameObject.h"
#include "composite/HealthComponent.h"
#include "composite/MoveComponent.h"
#include "composite/AttackComponent.h"
#include "visitor/LandMonster.h"
#include "visitor/AirMonster.h"
#include "visitor/EvolutionVisitor.h"


int main()
{

  std::cout << std::endl;
  std::cout << "Welcome to the Monster Test!" << std::endl;

  std::cout << "\n### Composite Pattern Test ###" << std::endl;

  // make a monster
  AirMonster airMonster = AirMonster(0.5f, 0.5f);
  LandMonster landMonster = LandMonster(2.0f);

  // testing duplicate game object
  std::cout << "\nTrying to add/remove a GameObject to an Air Monster..." << std::endl;
  GameObject go2;
  airMonster.add(&go2);
  airMonster.remove(&go2);

  // duplicate health component
  HealthComponent* health = new HealthComponent(10.0);

  std::cout << "\nTrying to add an extra Health Component to an Air Monster..." << std::endl;
  airMonster.add(health);
  airMonster.add(health);

  // duplicate movement object
  MoveComponent* move = new MoveComponent(5.0f);

  std::cout << "\nTrying to add an extra Move Component to an Air Monster..." << std::endl;
  airMonster.add(move);
  go2.add(move);  // no segmentation fault on delete

  // new attack component
  AttackComponent* attack = new AttackComponent(1.0f, 0.33f);

  airMonster.add(attack);
  
  std::cout << "\nAdding an Attack Component to a GameObject twice, then removing it..." << std::endl;
  go2.add(attack);
  go2.add(attack);
  go2.remove(attack);

  // run methods
  std::cout << "\nInitializing an Air Monster and a Land Monster..." << std::endl;
  airMonster.init();
  std::cout << std::endl;
  landMonster.init();

  std::cout << "\n### Visitor Pattern Test ###\n" << std::endl;
  
  // make the visitor
  EvolutionVisitor evoVisitor = EvolutionVisitor();

  airMonster.accept(evoVisitor);
  std::cout << std::endl;
  landMonster.accept(evoVisitor);

  std::cout << "\n=== Starting execute loop ===\n" << std::endl;

  for(int i = 0; i < 15; i++) {
    std::cout << "- Frame " << (i + 1) << " -" << std::endl;
    std::cout << "== Air Monster ==" << std::endl;
    airMonster.execute(0.1f);
    std::cout << std::endl;
    std::cout << "== Land Monster ==" << std::endl;
    landMonster.execute(0.1f);
    std::cout << std::endl;
  }

  return 0;
}
