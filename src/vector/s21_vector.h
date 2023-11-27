#ifndef CPP2_S21_CONTAINERS_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_VECTOR_S21_VECTOR_H_

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>

namespace s21 {

template <class T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  class VectorIterator {
   public:
    explicit VectorIterator(value_type *current);

    reference operator*();
    VectorIterator &operator++();
    VectorIterator operator++(int);
    VectorIterator &operator--();
    VectorIterator operator--(int);
    bool operator==(const VectorIterator &other) const;
    bool operator!=(const VectorIterator &other) const;

   private:
    value_type *current_;
    friend class vector<value_type>;
  };

  class VectorConstIterator : public VectorIterator {
   public:
    explicit VectorConstIterator(value_type *current);

    const_reference operator*() const;
  };

  using iterator = VectorIterator;
  using const_iterator = VectorConstIterator;

  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &other);
  vector(vector &&other) noexcept;
  ~vector();

  virtual vector<value_type> &operator=(
      std::initializer_list<value_type> const &items);
  vector<value_type> &operator=(const vector &other);
  vector<value_type> &operator=(vector &&other) noexcept;
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
  void reserve(size_type size);
  size_type capacity() const noexcept;
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other) noexcept;

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);

 protected:
  value_type *data_;
  size_type size_;
  size_type capacity_;
  std::allocator<value_type> alloc_;

  void Destroy();
};

}  // namespace s21

#include "s21_vector.tpp"

#endif  // CPP2_S21_CONTAINERS_VECTOR_S21_VECTOR_H_