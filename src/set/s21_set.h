#ifndef CPP2_S21_CONTAINERS_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_SET_S21_SET_H_

#include <initializer_list>
#include <iostream>
#include <memory>

#include "../vector/s21_vector.h"

namespace s21 {

template <class Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = Key&;
  using const_reference = const Key&;
  using size_type = size_t;

  enum Color { kBlack, kRed };

  struct Node {
    value_type value;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
  };

  class SetIterator {
   public:
    SetIterator(Node* current, Node* prev, Node* nil);

    reference operator*() const;
    SetIterator& operator++();
    SetIterator operator++(int);
    SetIterator& operator--();
    SetIterator operator--(int);
    bool operator==(const SetIterator& other);
    bool operator!=(const SetIterator& other);

   protected:
    Node* current_;
    Node* prev_;
    Node* iterator_nil_;
    friend class set<value_type>;
  };

  class SetConstIterator : public SetIterator {
   public:
    SetConstIterator(Node* current, Node* prev, Node* nil);
  };

  using iterator = SetIterator;
  using const_iterator = SetConstIterator;

  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& other);
  set(set&& other);
  ~set();

  virtual set<value_type>& operator=(
      std::initializer_list<value_type> const& items);
  set<value_type>& operator=(const set<value_type>& other);
  set<value_type>& operator=(set<value_type>&& other) noexcept;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other) noexcept;
  void merge(set& other);

  iterator find(value_type value);
  bool contains(const Key& key);

  template <class... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 protected:
  Node* root_;
  Node* nil_;
  std::allocator<Node> alloc_;

  static Node* FindMin(Node* node);
  static Node* FindMax(Node* node);
  void BalanceInsert(Node* node);
  void RotateLeft(Node* node);
  void RotateRight(Node* node);
  Node* FixLeftInsert(Node* node);
  Node* FixRightInsert(Node* node);
  void Transplant(Node* node_to_delete, Node* replacement);
  void BalanceErase(Node* node);
  Node* FixLeftErase(Node* node);
  Node* FixRightErase(Node* node);
  void ClearRecursive(Node* node);
};

}  // namespace s21

#include "s21_set.tpp"

#endif  // CPP2_S21_CONTAINERS_SET_S21_SET_H_