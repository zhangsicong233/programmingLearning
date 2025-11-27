#pragma once

struct ControlBlock {
  ControlBlock() : ref_count(1) {}

  int ref_count;
};

template <typename T>
class SimpleSharedPtr {
 public:
  SimpleSharedPtr() : ptr(nullptr), control(nullptr) {}

  explicit SimpleSharedPtr(T* p) : ptr(p) {
    if (p) {
      control = new ControlBlock();
    } else {
      control = nullptr;
    }
  }

  SimpleSharedPtr(const SimpleSharedPtr& other)
      : ptr(other.ptr), control(other.control) {
    if (control) {
      ++control->ref_count;
    }
  }

  SimpleSharedPtr(SimpleSharedPtr&& other) noexcept
      : ptr(other.ptr), control(other.control) {
    other.ptr = nullptr;
    other.control = nullptr;
  }

  SimpleSharedPtr& operator=(const SimpleSharedPtr& other) {
    if (this != &other) {
      release();

      ptr = other.ptr;
      control = other.control;
      if (control) {
        ++control->ref_count;
      }
    }

    return *this;
  }

  SimpleSharedPtr& operator=(SimpleSharedPtr&& other) noexcept {
    if (this != &other) {
      release();

      ptr = other.ptr;
      control = other.control;

      other.ptr = nullptr;
      other.control = nullptr;
    }

    return *this;
  }

  T* operator->() const { return ptr; }

  T& operator*() const { return *ptr; }

  T* get() const { return ptr; }

  int use_count() const { return control ? control->ref_count : 0; }

  void reset(T* p = nullptr) {
    release();

    ptr = p;
    if (p) {
      control = new ControlBlock();
    } else {
      control = nullptr;
    }
  }

  ~SimpleSharedPtr() {
    if (ptr) {
      release();
    }
  }

 private:
  void release() {
    if (control) {
      --control->ref_count;
      if (!control->ref_count) {
        delete ptr;
        delete control;

        ptr = nullptr;
        control = nullptr;
      }
    }
  }

  T* ptr;
  ControlBlock* control;
};