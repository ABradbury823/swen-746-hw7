#pragma once

class IComponent{
  public:
    virtual ~IComponent() {}
    /// @brief Function that runs once when component is first initialized.
    virtual void init() = 0;
    /// @brief Function that runs every frame.
    virtual void execute() = 0;
};