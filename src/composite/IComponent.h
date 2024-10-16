#pragma once

#include <iostream>

class IComponentAccess;

class IComponent {
protected:
  enum class ComponentType {
    GameObject,
    Health,
    Move,
    Attack
  };

public:
  virtual ~IComponent() {}

  /// @brief Function that runs once when component is first initialized.
  virtual void init() = 0;

  /// @brief Function that runs every frame.
  /// @param deltaTime Time since last call, in seconds.
  virtual void execute(float deltaTime) = 0;

  /// @brief Function that runs once when component is at the end of it's lifecycle.
  virtual void tearDown() = 0;

  /// @brief Retrieves the component's unique identifier.
  /// @return Enum identifier for class.
  virtual ComponentType getComponentType() const = 0;

  /// @brief Retrieve interface for accessing component references.
  /// @return The component access interface.
  virtual IComponentAccess* getAccess() = 0;
};

class IComponentAccess {
public:
  virtual ~IComponentAccess() {}

  /// @brief Add a component reference.
  virtual void addRef() = 0;
  /// @brief Remove a component reference.
  virtual void release() = 0;
};