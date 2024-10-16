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

  // make a monster
  AirMonster airMonster = AirMonster(0.5f, 0.5f);
  LandMonster landMonster = LandMonster(2.0f);

  // make the visitor
  EvolutionVisitor evoVisitor = EvolutionVisitor();

  airMonster.accept(&evoVisitor);
  landMonster.accept(&evoVisitor);

  // testing duplicate game object
  GameObject go2;
  airMonster.add(&go2);
  airMonster.remove(&go2);

  // duplicate health component
  HealthComponent* health = new HealthComponent(10.0);
  std::cout << "Health: " << airMonster.getHealthComponent()->getHealth() << std::endl;

  airMonster.add(health);
  airMonster.add(health);

  // new move component, components can only belong to one GameObject
  MoveComponent* move = new MoveComponent(5.0f);
  std::cout << "Position: " << move->getPosition().toString() << std::endl;

  airMonster.add(move);
  go2.add(move);  // no segmentation fault on delete

  // new attack component
  AttackComponent* attack = new AttackComponent(1.0f, 0.33f);

  airMonster.add(attack);
  
  go2.add(attack);
  go2.add(attack);
  go2.remove(attack);

  // run methods
  airMonster.init();
  landMonster.init();
  std::cout << "Health: " << airMonster.getHealthComponent()->getHealth() << std::endl;

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
