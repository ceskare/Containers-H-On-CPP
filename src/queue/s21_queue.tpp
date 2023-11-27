#ifndef CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_TPP_
#define CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_TPP_

#include "s21_queue.h"

namespace s21 {

template <class T>
queue<T>::queue() : list<T>() {}

template <class T>
queue<T>::queue(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <class T>
queue<T>::queue(const queue<T> &other) : list<T>(other) {}

template <class T>
queue<T>::queue(queue<T> &&other) noexcept : list<T>(std::move(other)) {}

template <class T>
queue<T> &queue<T>::operator=(std::initializer_list<value_type> const &items) {
  list<T>::operator=(items);
  return *this;
}

template <class T>
queue<T> &queue<T>::operator=(const queue<value_type> &other) {
  list<T>::operator=(other);
  return *this;
}

template <class T>
queue<T> &queue<T>::operator=(queue<value_type> &&other) noexcept {
  list<T>::operator=(std::move(other));
  return *this;
}

template <class T>
typename queue<T>::const_reference queue<T>::back() const {
  return list<T>::back();
}

template <class T>
typename queue<T>::const_reference queue<T>::front() const {
  return list<T>::front();
}

template <class T>
bool queue<T>::empty() const noexcept {
  return list<T>::empty();
}

template <class T>
typename queue<T>::size_type queue<T>::size() const noexcept {
  return list<T>::size();
}

template <class T>
void queue<T>::push(const_reference value) {
  list<T>::push_back(value);
}

template <class T>
void queue<T>::pop() {
  list<T>::pop_front();
}

template <class T>
void queue<T>::swap(queue &other) {
  list<T>::swap(other);
}

template <class T>
template <class... Args>
void queue<T>::insert_many_back(Args &&...args) {
  ((push(args)), ...);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_TPP_