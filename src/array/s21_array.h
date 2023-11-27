#ifndef CPP2_S21_CONTAINERS_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_ARRAY_S21_ARRAY_H_

#include "../vector/s21_vector.h"

namespace s21 {

template <class T, std::size_t N>
class array : private vector<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = typename vector<value_type>::iterator;
  using const_iterator = typename vector<value_type>::const_iterator;
  using size_type = size_t;

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other) noexcept;
  ~array() = default;

  array<T, N> &operator=(std::initializer_list<value_type> const &items);
  array<T, N> &operator=(const array<T, N> &other);
  array<T, N> &operator=(array<T, N> &&other) noexcept;

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  value_type *data();
  value_type *data() const;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void swap(array &other) noexcept;
  void fill(const_reference value);

 private:
  using vector<value_type>::data_;
};

}  // namespace s21

#include "s21_array.tpp"

#endif  // CPP2_S21_CONTAINERS_ARRAY_S21_ARRAY_H_