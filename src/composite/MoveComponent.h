#pragma once

#include "Component.h"
#include "../Vector.h"

class MoveComponent : public Component {
  private:
    float mMoveSpeed;
    float mMoveSpeedMultiplier;
    Vector mPosition;
    Vector mMoveDir;

  public:
    MoveComponent(float moveSpeed); // ctor
    ~MoveComponent();               // dtor

    /// @brief Retrieve movement speed.
    /// @return Movement speed, in units per second.
    inline float getMoveSpeed() const { return mMoveSpeed; }

    /// @brief Retrieve movement speed multiplier.
    /// @return Modifier to the movement speed each frame.
    inline float getMoveSpeedMult() const { return mMoveSpeedMultiplier; }
    
    void setMoveSpeedMult(float speedMult); // set move speed multiplier

    /// @brief Retrieve current position.
    /// @return Current world position.
    inline Vector getPosition() const { return mPosition; }

    void move(Vector newPos);   // move to new position

    void init() override;                             // runs once at start
    void execute(float deltaTime) override;           // runs every frame
    ComponentType getComponentType() const override;  // gets type = Move
};