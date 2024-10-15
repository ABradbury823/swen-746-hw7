#pragma once

class SharedResource {
  private:
    int mRefCount;

  public:
    SharedResource() : mRefCount(0) {}
    virtual ~SharedResource() {}

    inline int getRefCount() const { return mRefCount; }

    /// @brief Add a reference to an object.
    void addRef() {
      mRefCount++;
    }

    /// @brief Release the reference from an object.
    void release() {
      mRefCount--;
    }
};