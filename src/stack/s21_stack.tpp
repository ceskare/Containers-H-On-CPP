#ifndef CPP2_S21_CONTAINERS_STACK_S21_STACK_TPP_
#define CPP2_S21_CONTAINERS_STACK_S21_STACK_TPP_

#include "s21_stack.h"

namespace s21 {

template <class T>
stack<T>::stack() : list<T>() {}

template <class T>
stack<T>::stack(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <class T>
stack<T>::stack(const stack<T> &other) : list<T>(other) {}

template <class T>
stack<T>::stack(stack<T> &&other) noexcept : list<T>(std::move(other)) {}

template <class T>
stack<T> &stack<T>::operator=(std::initializer_list<value_type> const &items) {
  list<T>::operator=(items);
  return *this;
}

template <class T>
stack<T> &stack<T>::operator=(const stack<value_type> &other) {
  list<T>::operator=(other);
  return *this;
}

template <class T>
stack<T> &stack<T>::operator=(stack<value_type> &&other) noexcept {
  list<T>::operator=(std::move(other));
  return *this;
}

template <class T>
typename stack<T>::const_reference stack<T>::top() const {
  return list<T>::back();
}

template <class T>
bool stack<T>::empty() const noexcept {
  return list<T>::empty();
}

template <class T>
typename stack<T>::size_type stack<T>::size() const noexcept {
  return list<T>::size();
}

template <class T>
void stack<T>::push(const_reference value) {
  list<T>::push_back(value);
}

template <class T>
void stack<T>::pop() {
  list<T>::pop_back();
}

template <class T>
void stack<T>::swap(stack &other) {
  list<T>::swap(other);
}

template <class T>
template <class... Args>
void stack<T>::insert_many_front(Args &&...args) {
  ((push(args)), ...);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_STACK_S21_STACK_TPP_