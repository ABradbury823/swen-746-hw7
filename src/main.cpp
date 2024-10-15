#include <iostream>

#include "composite/GameObject.h"
#include "composite/HealthComponent.h"


int main()
{

  std::cout << std::endl;
  std::cout << "Hello C++ World from VS Code!" << std::endl;

  // make a game object
  GameObject go1 = GameObject();

  // testing game object
  GameObject go2 = GameObject();
  go1.add(&go2);
  go1.remove(&go2);

  // new health component
  HealthComponent* health = new HealthComponent(10);
  std::cout << "Health: " << health->getHealth() << std::endl;

  go1.add(health);
  go1.add(health);

  // run methods
  go1.init();
  std::cout << "Health: " << health->getHealth() << std::endl;
  go1.execute();

  return 0;
}
