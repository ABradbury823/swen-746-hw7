#pragma once

#include "Component.h"
#include "../Vector.h"

class MoveComponent : public Component {
  private:
    float mMoveSpeed;
    Vector mPosition;
    Vector mMoveDir;

  public:
    MoveComponent(float moveSpeed); // ctor
    ~MoveComponent();               // dtor

    /// @brief Retrieve movement speed.
    /// @return Movement speed, in units per second.
    inline float getMoveSpeed() const { return mMoveSpeed; }
    /// @brief Retrieve current position.
    
    /// @return Current world position.
    inline Vector getPosition() const { return mPosition; }

    void move(Vector newPos);

    void init() override;                             // runs once at start
    void execute(float deltaTime) override;           // runs every frame
    ComponentType getComponentType() const override;  // gets type = Move
};