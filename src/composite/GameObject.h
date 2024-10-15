#pragma once

#include <vector>

#include "IComponent.h"

class GameObject : public IComponent
{
private:
  std::vector<IComponent*> mComponents;

public:
  GameObject();   // ctor
  ~GameObject();  // dtor

  void add(IComponent* c);    // add component
  void remove(IComponent* c); // remove component
  inline std::vector<IComponent*> getComponents() const { return mComponents; }
  IComponent* getComponentByType(ComponentType type) const;

  virtual void init() override;     // runs on start
  virtual void execute() override;  // runs every frame
  virtual ComponentType getComponentType() const override;  // gets type = GameObject
};
