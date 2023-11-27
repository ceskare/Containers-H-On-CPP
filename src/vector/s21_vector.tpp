#ifndef CPP2_S21_CONTAINERS_VECTOR_S21_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_VECTOR_S21_VECTOR_TPP_

#include "s21_vector.h"

namespace s21 {

template <class T>
vector<T>::VectorIterator::VectorIterator(value_type* current)
    : current_(current) {}

template <class T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() {
  return *current_;
}

template <class T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator++() {
  ++current_;
  return *this;
}

template <class T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(int) {
  VectorIterator temp(current_++);
  return temp;
}

template <class T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator--() {
  --current_;
  return *this;
}

template <class T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(int) {
  VectorIterator temp(current_--);
  return temp;
}

template <class T>
bool vector<T>::VectorIterator::operator==(const VectorIterator& other) const {
  return current_ == other.current_;
}

template <class T>
bool vector<T>::VectorIterator::operator!=(const VectorIterator& other) const {
  return current_ != other.current_;
}

template <class T>
vector<T>::VectorConstIterator::VectorConstIterator(value_type* current)
    : VectorIterator(current) {}

template <class T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const {
  return *VectorIterator::current_;
}

template <class T>
vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {}

template <class T>
vector<T>::vector(size_type n) : size_(n), capacity_(n) {
  data_ = alloc_.allocate(n);
  for (size_type i = 0; i < size_; ++i) {
    data_[i] = value_type{};
  }
}

template <class T>
vector<T>::vector(std::initializer_list<value_type> const& items)
    : size_(items.size()), capacity_(items.size()) {
  data_ = alloc_.allocate(items.size());
  std::uninitialized_copy(items.begin(), items.end(), data_);
}

template <class T>
vector<T>::vector(const vector& other)
    : size_(other.size_), capacity_(other.capacity_) {
  data_ = alloc_.allocate(other.capacity_);
  std::uninitialized_copy(other.data_, other.data_ + other.size_, data_);
}

template <class T>
vector<T>::vector(vector&& other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <class T>
vector<T>::~vector() {
  Destroy();
}

template <class T>
vector<T>& vector<T>::operator=(
    std::initializer_list<value_type> const& items) {
  Destroy();
  size_ = items.size();
  capacity_ = size_;
  data_ = alloc_.allocate(capacity_);
  std::uninitialized_copy(items.begin(), items.end(), data_);
  return *this;
}

template <class T>
vector<T>& vector<T>::operator=(const vector& other) {
  if (this != &other) {
    Destroy();
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = alloc_.allocate(capacity_);
    std::uninitialized_copy(other.data_, other.data_ + other.size_, data_);
  }
  return *this;
}

template <class T>
vector<T>& vector<T>::operator=(vector&& other) noexcept {
  if (this != &other) {
    swap(other);
    other.Destroy();
  }
  return *this;
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return data_[pos];
}

template <class T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  return data_[pos];
}

template <class T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) throw std::out_of_range("Incorrect index of a container!");
  return data_[pos];
}

template <class T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (pos >= size_) throw std::out_of_range("Incorrect index of a container!");
  return data_[pos];
}

template <class T>
typename vector<T>::const_reference vector<T>::front() const {
  return data_[0];
}

template <class T>
typename vector<T>::const_reference vector<T>::back() const {
  return data_[size_ - 1];
}

template <class T>
typename vector<T>::value_type* vector<T>::data() {
  return data_;
}

template <class T>
typename vector<T>::value_type* vector<T>::data() const {
  return data_;
}

template <class T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}

template <class T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

template <class T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return const_iterator(data_);
}

template <class T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return const_iterator(data_ + size_);
}

template <class T>
bool vector<T>::empty() const noexcept {
  return (size_ == 0);
}

template <class T>
typename vector<T>::size_type vector<T>::size() const noexcept {
  return size_;
}

template <class T>
typename vector<T>::size_type vector<T>::max_size() const noexcept {
  return alloc_.max_size();
}

template <class T>
void vector<T>::reserve(size_type size) {
  if (size > capacity_) {
    value_type* temp = alloc_.allocate(size);
    std::uninitialized_copy(data_, data_ + size_, temp);
    alloc_.deallocate(data_, capacity_);
    data_ = temp;
    capacity_ = size;
  }
}

template <class T>
typename vector<T>::size_type vector<T>::capacity() const noexcept {
  return capacity_;
}

template <class T>
void vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    value_type* temp = alloc_.allocate(size_);
    std::uninitialized_copy(data_, data_ + size_, temp);
    alloc_.deallocate(data_, capacity_);
    data_ = temp;
    capacity_ = size_;
  }
}

template <class T>
void vector<T>::clear() {
  size_ = 0;
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type index = pos.current_ - begin().current_;
  if (size_ == capacity_) {
    reserve((capacity_) ? capacity_ * 2 : 1);
  }
  std::uninitialized_copy(data_ + index, data_ + size_, data_ + index + 1);
  data_[index] = value;
  size_++;
  return iterator(data_ + index);
}

template <class T>
void vector<T>::erase(iterator pos) {
  size_type index = pos.current_ - begin().current_;
  std::uninitialized_copy(data_ + index + 1, data_ + size_, data_ + index);
  size_--;
}

template <class T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve((capacity_) ? capacity_ * 2 : 1);
  }
  data_[size_++] = value;
}

template <class T>
void vector<T>::pop_back() {
  if (size_ > 0) {
    size_--;
  }
}

template <class T>
void vector<T>::swap(vector& other) noexcept {
  if (this != &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }
}

template <class T>
template <class... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args&&... args) {
  size_type index = pos.current_ - data_;
  ((insert(iterator(data_ + index), args)), ...);
  return iterator(data_ + index);
}

template <class T>
template <class... Args>
void vector<T>::insert_many_back(Args&&... args) {
  ((push_back(args)), ...);
}

template <class T>
void vector<T>::Destroy() {
  alloc_.deallocate(data_, capacity_);
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_VECTOR_S21_VECTOR_TPP_