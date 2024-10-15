#pragma once

#include <vector>

#include "IComponent.h"

class GameObject : public IComponent
{
private:
  std::vector<IComponent*> mComponents;

public:
  ~GameObject();  // dtor

  void add(IComponent* c);    // add component
  void remove(IComponent* c); // remove component
  inline std::vector<IComponent*> getComponents() const { return mComponents; }
  IComponent* getComponentByType(ComponentType type) const;
  IComponentAccess* getAccess() override { return nullptr; };

  virtual void init() override;     // runs on start
  virtual void execute(float deltaTime) override;  // runs every frame
  virtual void tearDown() override;   // runs at end  
  virtual ComponentType getComponentType() const override;  // gets type = GameObject
};
