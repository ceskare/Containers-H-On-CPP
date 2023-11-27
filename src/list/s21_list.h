#ifndef CPP2_S21_CONTAINERS_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_LIST_S21_LIST_H_

#include <initializer_list>
#include <iostream>
#include <memory>

namespace s21 {

template <class T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  struct Node {
    value_type value;
    Node *prev = nullptr;
    Node *next = nullptr;
  };

  class ListIterator {
   public:
    ListIterator(Node *current, Node *prev);

    reference operator*();
    ListIterator &operator++();
    ListIterator operator++(int);
    ListIterator &operator--();
    ListIterator operator--(int);
    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;

   private:
    Node *current_;
    Node *prev_;
    friend class list<value_type>;
  };

  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator(Node *current, Node *prev);

    const_reference operator*() const;
  };

  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  list();
  explicit list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &other);
  list(list &&other) noexcept;
  ~list();

  list<value_type> &operator=(std::initializer_list<value_type> const &items);
  list<value_type> &operator=(const list<value_type> &other);
  list<value_type> &operator=(list<value_type> &&other) noexcept;

  const_reference front() const;
  const_reference back() const;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference item);
  void push_front(const_reference item);
  void pop_back();
  void pop_front();
  void swap(list &other) noexcept;
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <class... Args>
  void insert_many_back(Args &&...args);

  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  Node *head_;
  Node *tail_;
  std::allocator<Node> alloc_;

  Node *Split(Node *head);
  Node *Merge(Node *first, Node *second);
  Node *MergeSort(Node *head);
  void ConnectNodes(Node *first, Node *second);
};

}  // namespace s21

#include "s21_list.tpp"

#endif  // CPP2_S21_CONTAINERS_LIST_S21_LIST_H_