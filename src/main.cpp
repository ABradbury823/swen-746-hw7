#include <iostream>

#include "composite/GameObject.h"


int main()
{

  std::cout << std::endl;
  std::cout << "Hello C++ World from VS Code!" << std::endl;

  // make a game object
  GameObject* go1 = new GameObject();
  go1->init();
  go1->execute();

  delete go1;

  return 0;
}
