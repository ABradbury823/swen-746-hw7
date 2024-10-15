#pragma once

#include "IComponent.h"

class MoveComponent : public IComponent {
  private:
    float mMoveSpeed;

  public:
    MoveComponent(float moveSpeed); // ctor
    ~MoveComponent();               // dtor

    /// @brief Retrieve movement speed.
    /// @return Movement speed, in units per second.
    inline float getMoveSpeed() const { return mMoveSpeed; }

    void move(float deltaTime);

    void init() override;
    void execute() override;
    ComponentType getComponentType() const override;
};