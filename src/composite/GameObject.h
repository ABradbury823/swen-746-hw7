#include "IComponent.h"

#include <vector>

class GameObject : IComponent
{
private:
  std::vector<IComponent> mComponents;
public:
  GameObject();   // ctor
  ~GameObject();  // dtor

  void add(IComponent& c);    // add component
  void remove(IComponent& c); // remove component
  inline std::vector<IComponent> getComponents() {return mComponents;}

  void init() override;     // runs on start
  void execute() override;  // runs every frame
};

GameObject::GameObject(/* args */)
{
}

GameObject::~GameObject()
{
}
