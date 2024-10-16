#include "composite/GameObject.h"
#include "composite/HealthComponent.h"
#include "composite/MoveComponent.h"
#include "composite/AttackComponent.h"
#include "visitor/LandMonster.h"


int main()
{

  std::cout << std::endl;
  std::cout << "Hello C++ World from VS Code!" << std::endl;

  // make a monster
  LandMonster monster1 = LandMonster(2.0f);

  // testing game object
  GameObject go2;
  monster1.add(&go2);
  monster1.remove(&go2);

  // duplicate health component
  HealthComponent* health = new HealthComponent(10.0);
  std::cout << "Health: " << monster1.getHealthComponent()->getHealth() << std::endl;

  monster1.add(health);
  monster1.add(health);

  // new move component, components can only belong to one GameObject
  MoveComponent* move = new MoveComponent(5.0f);
  std::cout << "Position: " << move->getPosition().toString() << std::endl;

  monster1.add(move);
  go2.add(move);  // no segmentation fault on delete

  // new attack component
  AttackComponent* attack = new AttackComponent(1.0f, 0.33f);

  go2.add(attack);
  go2.add(attack);
  monster1.add(attack);
  go2.remove(attack);

  // run methods
  monster1.init();
  std::cout << "Health: " << monster1.getHealthComponent()->getHealth() << std::endl;

  std::cout << "\n=== Starting execute loop ===\n" << std::endl;

  for(int i = 0; i < 10; i++) {
    std::cout << "- Frame " << (i + 1) << " -" << std::endl;
    monster1.execute(0.1f);
    std::cout << std::endl;
  }

  return 0;
}
