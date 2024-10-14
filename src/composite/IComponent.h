#pragma once

class IComponent{
  public:
    virtual ~IComponent() {}
    virtual void init() = 0;
    virtual void execute() = 0;
};