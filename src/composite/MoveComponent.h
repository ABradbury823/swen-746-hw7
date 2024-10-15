#pragma once

#include "Component.h"

class MoveComponent : public Component {
  private:
    float mMoveSpeed;

  public:
    MoveComponent(float moveSpeed); // ctor
    ~MoveComponent();               // dtor

    /// @brief Retrieve movement speed.
    /// @return Movement speed, in units per second.
    inline float getMoveSpeed() const { return mMoveSpeed; }

    void move(float deltaTime);

    void init() override;                             // runs once at start
    void execute(float deltaTime) override;           // runs every frame
    ComponentType getComponentType() const override;  // gets type = Move
};