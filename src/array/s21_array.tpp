#ifndef CPP2_S21_CONTAINERS_ARRAY_S21_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_ARRAY_S21_ARRAY_TPP_

#include "s21_array.h"

namespace s21 {

template <class T, std::size_t N>
array<T, N>::array() : vector<value_type>(N) {}

template <class T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : array() {
  if (items.size() > N) {
    throw std::out_of_range("Too many initializers!");
  }
  std::uninitialized_copy(items.begin(), items.end(), data_);
}

template <class T, std::size_t N>
array<T, N>::array(const array &other) : vector<T>(other) {}

template <class T, std::size_t N>
array<T, N>::array(array &&other) noexcept : vector<T>(other) {}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(
    std::initializer_list<value_type> const &items) {
  if (items.size() > N) {
    throw std::out_of_range("Too many initializers!");
  }
  vector<T>::operator=(items);
  return *this;
}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(const array<T, N> &other) {
  vector<T>::operator=(other);
  return *this;
}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(array<T, N> &&other) noexcept {
  vector<value_type>::swap(other);
  return *this;
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return vector<T>::operator[](pos);
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const {
  return vector<T>::operator[](pos);
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  return vector<T>::at(pos);
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  return vector<T>::at(pos);
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return vector<T>::front();
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return vector<T>::back();
}

template <class T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::data() {
  return vector<T>::data();
}

template <class T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::data() const {
  return vector<T>::data();
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return vector<T>::begin();
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return vector<T>::end();
}

template <class T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cbegin() const {
  return vector<T>::cbegin();
}

template <class T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cend() const {
  return vector<T>::cend();
}

template <class T, std::size_t N>
bool array<T, N>::empty() const noexcept {
  return vector<T>::empty();
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return vector<T>::size();
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return vector<T>::size();
}

template <class T, std::size_t N>
void array<T, N>::swap(array &other) noexcept {
  vector<T>::swap(other);
}

template <class T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i != N; ++i) {
    data_[i] = value;
  }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_ARRAY_S21_ARRAY_TPP_