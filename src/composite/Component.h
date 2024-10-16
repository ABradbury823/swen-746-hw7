#pragma once

#include "SharedResource.h"
#include "IComponent.h"

class Component : public virtual IComponent, public virtual IComponentAccess{
  private:
    SharedResource mResource;
  
  public:
    virtual ~Component() {
      tearDown();
    }

    virtual void init() override = 0;
    virtual void execute(float deltaTime) override = 0;
    virtual void tearDown() override {};
    virtual ComponentType getComponentType() const override = 0;

    /// @brief Retrieve interface for accessing component references.
    /// @return The component access interface.
    IComponentAccess* getAccess() override {
      return this;
    }

    /// @brief Add a component reference.
    void addRef() override {
      mResource.addRef();
    }

    /// @brief Remove a component reference.
    void release() override {
      mResource.release();
      if(mResource.getRefCount() == 0) {
        delete this;
      }
    }
};