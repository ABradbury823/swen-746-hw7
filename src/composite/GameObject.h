#pragma once

#include <vector>

#include "IComponent.h"

class GameObject : public IComponent
{
private:
  std::vector<IComponent*> mComponents;

public:
  virtual ~GameObject();  // dtor

  virtual void add(IComponent* c) final;    // add component
  virtual void remove(IComponent* c) final; // remove component
  virtual inline std::vector<IComponent*> getComponents() const final { return mComponents; }
  virtual IComponent* getComponentByType(ComponentType type) const final;   // Return = GameObject
  virtual IComponentAccess* getAccess() final override { return nullptr; }; // no access on GameObjects

  virtual void init() override;     // runs on start
  virtual void execute(float deltaTime) override;  // runs every frame
  virtual void tearDown() override;   // runs at end  
  virtual ComponentType getComponentType() const override final;  // gets type = GameObject
};
