#pragma once

#include "Component.h"

class HealthComponent : public Component {
private:
  float mHealth;
  float mMaxHealth;
  bool mIsAlive;

public:
  HealthComponent(float maxHealth);  // ctor
  ~HealthComponent(); // dtor

  inline float getHealth() const { return mHealth; }  // get health
  inline bool isAlive() const { return mIsAlive; }    // get is alive

  void restoreHealth(float amount);   // increase health
  void takeDamage(float amount);      // decrease health
  void die();                         // health <= 0

  void init() override;                             // runs once at start
  void execute(float deltaTime) override;           // runs every frame
  ComponentType getComponentType() const override;  // gets type = Health
};