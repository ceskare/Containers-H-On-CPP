#ifndef CPP2_S21_CONTAINERS_LIST_S21_LIST_TPP_
#define CPP2_S21_CONTAINERS_LIST_S21_LIST_TPP_

#include "s21_list.h"

namespace s21 {

template <class T>
list<T>::ListIterator::ListIterator(Node* current, Node* prev)
    : current_(current), prev_(prev) {}

template <class T>
typename list<T>::reference list<T>::ListIterator::operator*() {
  return current_->value;
}

template <class T>
typename list<T>::ListIterator& list<T>::ListIterator::operator++() {
  if (!current_) {
    current_ = prev_;
  } else {
    prev_ = current_;
    current_ = current_->next;
  }
  return *this;
}

template <class T>
typename list<T>::ListIterator list<T>::ListIterator::operator++(int) {
  ListIterator temp = *this;
  ++(*this);
  return temp;
}

template <class T>
typename list<T>::ListIterator& list<T>::ListIterator::operator--() {
  if (!current_) {
    current_ = prev_;
  } else {
    prev_ = current_;
    current_ = current_->prev;
  }
  return *this;
}

template <class T>
typename list<T>::ListIterator list<T>::ListIterator::operator--(int) {
  ListIterator temp = *this;
  --(*this);
  return temp;
}

template <class T>
bool list<T>::ListIterator::operator==(const ListIterator& other) const {
  return current_ == other.current_;
}

template <class T>
bool list<T>::ListIterator::operator!=(const ListIterator& other) const {
  return current_ != other.current_;
}

template <class T>
list<T>::ListConstIterator::ListConstIterator(Node* current, Node* prev)
    : ListIterator(current, prev) {}

template <class T>
typename list<T>::const_reference list<T>::ListConstIterator::operator*()
    const {
  return ListIterator::current_->value;
}

template <class T>
list<T>::list() : head_(nullptr), tail_(nullptr) {}

template <class T>
list<T>::list(size_type n) : list() {
  for (auto i = 0; i != n; ++i) {
    push_back(value_type{});
  }
}

template <class T>
list<T>::list(std::initializer_list<T> const& items) : list() {
  for (auto it = items.begin(); it != items.end(); ++it) {
    push_back(*it);
  }
}

template <class T>
list<T>::list(const list& other) : list() {
  for (auto it = other.cbegin(); it != other.cend(); ++it) {
    push_back(*it);
  }
}

template <class T>
list<T>::list(list&& other) noexcept : head_(other.head_), tail_(other.tail_) {
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

template <class T>
list<T>::~list() {
  clear();
}

template <class T>
list<T>& list<T>::operator=(std::initializer_list<T> const& items) {
  clear();
  for (auto it = items.begin(); it != items.end(); ++it) {
    push_back(*it);
  }
  return *this;
}

template <class T>
list<T>& list<T>::operator=(const list<T>& other) {
  if (this != &other) {
    clear();
    for (auto it = other.cbegin(); it != other.cend(); ++it) {
      push_back(*it);
    }
  }
  return *this;
}

template <class T>
list<T>& list<T>::operator=(list<T>&& other) noexcept {
  if (this != &other) {
    swap(other);
    other.clear();
  }
  return *this;
}

template <class T>
typename list<T>::const_reference list<T>::front() const {
  return head_->value;
}

template <class T>
typename list<T>::const_reference list<T>::back() const {
  return tail_->value;
}

template <class T>
typename list<T>::iterator list<T>::begin() {
  return iterator(head_, nullptr);
}

template <class T>
typename list<T>::iterator list<T>::end() {
  return iterator(nullptr, tail_);
}

template <class T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(head_, nullptr);
}

template <class T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(nullptr, tail_);
}

template <class T>
bool list<T>::empty() const noexcept {
  return head_ == nullptr;
}

template <class T>
typename list<T>::size_type list<T>::size() const noexcept {
  size_type size = 0;
  for (auto it = cbegin(); it != cend(); ++it) {
    ++size;
  }
  return size;
}

template <class T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return alloc_.max_size();
}

template <class T>
void list<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    return begin();
  }
  if (pos == end()) {
    push_back(value);
    return --end();
  }
  Node* new_node = alloc_.allocate(1);
  new_node->value = value;
  ConnectNodes(pos.current_->prev, new_node);
  ConnectNodes(new_node, pos.current_);
  return iterator(new_node, new_node->prev);
}

template <class T>
void list<T>::erase(iterator pos) {
  if (pos == begin()) {
    pop_front();
    return;
  }
  if (pos.current_ == tail_) {
    pop_back();
    return;
  }
  Node* temp_node = pos.current_;
  if (temp_node) {
    ConnectNodes(temp_node->prev, temp_node->next);
    alloc_.destroy(temp_node);
    alloc_.deallocate(temp_node, 1);
  }
}

template <class T>
void list<T>::push_back(const_reference item) {
  Node* new_node = alloc_.allocate(1);
  alloc_.construct(new_node, Node{item, nullptr, nullptr});
  if (tail_) {
    ConnectNodes(tail_, new_node);
  }
  tail_ = new_node;
  if (!head_) head_ = new_node;
}

template <class T>
void list<T>::push_front(const_reference item) {
  Node* new_node = alloc_.allocate(1);
  alloc_.construct(new_node, Node{item, nullptr, nullptr});
  if (!head_) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    ConnectNodes(new_node, head_);
    head_ = new_node;
  }
}

template <class T>
void list<T>::pop_back() {
  Node* temp_node = tail_;
  tail_ = tail_->prev;
  if (tail_) {
    tail_->next = nullptr;
  } else {
    head_ = nullptr;
  }
  alloc_.destroy(temp_node);
  alloc_.deallocate(temp_node, 1);
}

template <class T>
void list<T>::pop_front() {
  Node* temp_node = head_;
  head_ = head_->next;
  if (head_) {
    head_->prev = nullptr;
  } else {
    tail_ = nullptr;
  }
  alloc_.destroy(temp_node);
  alloc_.deallocate(temp_node, 1);
}

template <class T>
void list<T>::swap(list<T>& other) noexcept {
  if (this != &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
  }
}

template <class T>
void list<T>::merge(list& other) {
  if (this != &other) {
    ConnectNodes(tail_, other.head_);
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
}

template <class T>
void list<T>::splice(const_iterator pos, list& other) {
  if (this != &other) {
    if (pos == cbegin()) {
      ConnectNodes(other.tail_, pos.current_);
      head_ = other.head_;
    } else if (pos == cend()) {
      ConnectNodes(tail_, other.head_);
      tail_ = other.tail_;
    } else {
      Node* temp = pos.current_->prev;
      ConnectNodes(other.tail_, pos.current_);
      ConnectNodes(temp, other.head_);
    }
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
}

template <class T>
void list<T>::reverse() {
  auto it = begin();
  while (it.current_) {
    std::swap(it.current_->prev, it.current_->next);
    --it;
  }
  std::swap(head_, tail_);
}

template <class T>
void list<T>::unique() {
  auto temp = begin();
  for (auto it = ++begin(); it != end(); ++it) {
    if (*temp == *it) {
      erase(temp);
    }
    temp = it;
  }
}

template <class T>
void list<T>::sort() {
  head_ = MergeSort(head_);
  tail_ = head_;
  while (tail_ && tail_->next) {
    tail_ = tail_->next;
  }
}

template <class T>
typename list<T>::Node* list<T>::Split(Node* head) {
  Node *fast = head, *slow = head;
  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  Node* temp = slow->next;
  slow->next = nullptr;
  return temp;
}

template <class T>
typename list<T>::Node* list<T>::Merge(Node* first, Node* second) {
  if (!first) {
    return second;
  }
  if (!second) {
    return first;
  }
  if (first->value < second->value) {
    first->next = Merge(first->next, second);
    first->next->prev = first;
    first->prev = nullptr;
    return first;
  }
  second->next = Merge(first, second->next);
  second->next->prev = second;
  second->prev = nullptr;
  return second;
}

template <class T>
typename list<T>::Node* list<T>::MergeSort(Node* head) {
  if (!head || !head->next) {
    return head;
  }
  Node* second = Split(head);
  head = MergeSort(head);
  second = MergeSort(second);
  return Merge(head, second);
}

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  ((insert(pos, args)), ...);
  return pos;
}

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args&&... args) {
  ((push_back(args)), ...);
}

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args&&... args) {
  ((push_front(args)), ...);
}

template <class T>
void list<T>::ConnectNodes(Node* first, Node* second) {
  first->next = second;
  second->prev = first;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_LIST_S21_LIST_TPP_