#ifndef CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {

template <class T>
class queue : private list<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue();
  queue(std::initializer_list<value_type> const &item);
  queue(const queue &other);
  queue(queue &&other) noexcept;
  ~queue() = default;

  queue<value_type> &operator=(std::initializer_list<value_type> const &items);
  queue<value_type> &operator=(const queue<value_type> &other);
  queue<value_type> &operator=(queue<value_type> &&other) noexcept;

  const_reference back() const;
  const_reference front() const;

  bool empty() const noexcept;
  size_type size() const noexcept;

  void push(const_reference value);
  void pop();
  void swap(queue &other);

  template <class... Args>
  void insert_many_back(Args &&...args);
};

}  // namespace s21

#include "s21_queue.tpp"

#endif  // CPP2_S21_CONTAINERS_QUEUE_S21_QUEUE_H_