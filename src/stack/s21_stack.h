#ifndef CPP2_S21_CONTAINERS_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_STACK_S21_STACK_H_

#include "../list/s21_list.h"

namespace s21 {

template <class T>
class stack : private list<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();
  stack(std::initializer_list<value_type> const &item);
  stack(const stack &other);
  stack(stack &&other) noexcept;
  ~stack() = default;

  stack<value_type> &operator=(std::initializer_list<value_type> const &items);
  stack<value_type> &operator=(const stack<value_type> &other);
  stack<value_type> &operator=(stack<value_type> &&other) noexcept;

  const_reference top() const;

  bool empty() const noexcept;
  size_type size() const noexcept;

  void push(const_reference value);
  void pop();
  void swap(stack &other);

  template <class... Args>
  void insert_many_front(Args &&...args);
};

}  // namespace s21

#include "s21_stack.tpp"

#endif  // CPP2_S21_CONTAINERS_STACK_S21_STACK_H_