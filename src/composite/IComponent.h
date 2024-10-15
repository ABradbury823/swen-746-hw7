#pragma once

class IComponent{
protected:
  enum class ComponentType {
    GameObject,
    Health,
    Movement,
    Attack
  };

public:
  virtual ~IComponent() {}

  /// @brief Function that runs once when component is first initialized.
  virtual void init() = 0;

  /// @brief Function that runs every frame.
  virtual void execute() = 0;

  /// @brief Retrieves the component's unique identifier.
  /// @return Enum identifier for class.
  virtual ComponentType getComponentType() const = 0;
};