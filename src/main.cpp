#include <iostream>

#include "composite/GameObject.h"
#include "composite/HealthComponent.h"
#include "composite/MoveComponent.h"


int main()
{

  std::cout << std::endl;
  std::cout << "Hello C++ World from VS Code!" << std::endl;

  // make a game object
  GameObject go1;

  // testing game object
  GameObject go2;
  go1.add(&go2);
  go1.remove(&go2);

  // new health component
  HealthComponent* health = new HealthComponent(10);
  std::cout << "Health: " << health->getHealth() << std::endl;

  go1.add(health);
  go1.add(health);

  // new move component, components can only belong to one GameObject
  MoveComponent* move = new MoveComponent(5);
  std::cout << "Position: " << move->getPosition().toString() << std::endl;

  go1.add(move);
  go2.add(move);  // segmentation fault on delete

  // run methods
  go1.init();
  std::cout << "Health: " << health->getHealth() << std::endl;

  for(int i = 0; i < 10; i++){
    go1.execute(0.1f);
  }

  return 0;
}
