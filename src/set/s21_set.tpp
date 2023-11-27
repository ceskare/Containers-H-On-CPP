#ifndef CPP2_S21_CONTAINERS_SET_S21_SET_TPP_
#define CPP2_S21_CONTAINERS_SET_S21_SET_TPP_

#include "s21_set.h"

namespace s21 {

template <class Key>
set<Key>::SetIterator::SetIterator(Node* current, Node* prev, Node* nil)
    : current_(current), prev_(prev), iterator_nil_(nil) {}

template <class Key>
typename set<Key>::reference set<Key>::SetIterator::operator*() const {
  return current_->value;
}

template <class Key>
typename set<Key>::SetIterator& set<Key>::SetIterator::operator++() {
  if (current_ == iterator_nil_) {
    return *this;
  }
  if (current_->right != iterator_nil_) {
    current_ = current_->right;
    current_ = FindMin(current_);
  } else {
    Node* parent = current_->parent;
    while (parent && current_ == parent->right) {
      current_ = parent;
      parent = parent->parent;
    }
    current_ = parent;
  }
  prev_ = current_->parent;
  return *this;
}

template <class Key>
typename set<Key>::SetIterator set<Key>::SetIterator::operator++(int) {
  SetIterator temp = *this;
  ++(*this);
  return temp;
}
template <class Key>
typename set<Key>::SetIterator& set<Key>::SetIterator::operator--() {
  if (current_ == iterator_nil_) {
    current_ = prev_;
    return *this;
  }
  if (current_->left != iterator_nil_) {
    current_ = current_->left;
    current_ = FindMax(current_);
  } else {
    Node* parent = current_->parent;
    while (parent && current_ == parent->left) {
      current_ = parent;
      parent = parent->parent;
    }
    current_ = parent;
  }
  prev_ = current_->parent;
  return *this;
}

template <class Key>
typename set<Key>::SetIterator set<Key>::SetIterator::operator--(int) {
  SetIterator temp = *this;
  --(*this);
  return temp;
}

template <class Key>
bool set<Key>::SetIterator::operator==(const SetIterator& other) {
  return current_ == other.current_;
}

template <class Key>
bool set<Key>::SetIterator::operator!=(const SetIterator& other) {
  return current_ != other.current_;
}

template <class Key>
set<Key>::SetConstIterator::SetConstIterator(Node* current, Node* prev,
                                             Node* nil)
    : SetIterator(current, prev, nil) {}

template <class Key>
set<Key>::set() {
  nil_ = alloc_.allocate(1);
  alloc_.construct(nil_, Node{value_type(), kBlack, nullptr, nullptr, nullptr});
  root_ = nil_;
}

template <class Key>
set<Key>::set(std::initializer_list<value_type> const& items) : set() {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <class Key>
set<Key>::set(const set& other) : set() {
  for (auto it = other.cbegin(); it != other.cend(); ++it) {
    insert(*it);
  }
}

template <class Key>
set<Key>::set(set&& other) : set() {
  swap(other);
}

template <class Key>
set<Key>::~set() {
  clear();
  alloc_.deallocate(nil_, 1);
}

template <class Key>
set<Key>& set<Key>::operator=(std::initializer_list<Key> const& items) {
  clear();
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
  return *this;
}

template <class Key>
set<Key>& set<Key>::operator=(const set<Key>& other) {
  if (this != &other) {
    clear();
    for (auto it = other.cbegin(); it != other.cend(); ++it) {
      insert(*it);
    }
  }
  return *this;
}

template <class Key>
set<Key>& set<Key>::operator=(set<Key>&& other) noexcept {
  if (this != &other) {
    swap(other);
    other.clear();
  }
  return *this;
}

template <class Key>
typename set<Key>::iterator set<Key>::begin() {
  if (nil_ == nullptr) std::cout << "hello" << std::endl;
  return iterator(FindMin(root_), nil_, nil_);
}

template <class Key>
typename set<Key>::iterator set<Key>::end() {
  return iterator(nil_, FindMax(root_), nil_);
}

template <class Key>
typename set<Key>::const_iterator set<Key>::cbegin() const {
  return const_iterator(FindMin(root_), nil_, nil_);
}

template <class Key>
typename set<Key>::const_iterator set<Key>::cend() const {
  return const_iterator(nil_, FindMax(root_), nil_);
}

template <class Key>
typename set<Key>::Node* set<Key>::FindMin(Node* node) {
  while (node->left && node->left->left) {
    node = node->left;
  }
  return node;
}

template <class Key>
typename set<Key>::Node* set<Key>::FindMax(Node* node) {
  while (node->right && node->right->right) {
    node = node->right;
  }
  return node;
}

template <class Key>
bool set<Key>::empty() const noexcept {
  return (root_ == nil_);
}

template <class Key>
typename set<Key>::size_type set<Key>::size() const noexcept {
  size_type size = 0;
  for (auto it = cbegin(); it != cend(); ++it) {
    ++size;
  }
  return size;
}

template <class Key>
typename set<Key>::size_type set<Key>::max_size() const noexcept {
  return alloc_.max_size();
}

template <class Key>
void set<Key>::clear() {
  ClearRecursive(root_);
  root_ = nil_;
}

template <class Key>
void set<Key>::ClearRecursive(Node* node) {
  if (node == nil_) {
    return;
  }
  ClearRecursive(node->left);
  ClearRecursive(node->right);
  alloc_.destroy(node);
  alloc_.deallocate(node, 1);
}

template <class Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  bool status = true;
  Node* parent = nil_;
  Node* current = root_;
  while (current != nil_) {
    parent = current;
    if (value < current->value) {
      current = current->left;
    } else if (value > current->value) {
      current = current->right;
    } else {
      break;
    }
  }
  if (parent != nil_ && parent->value == value) {
    status = false;
  } else {
    current = alloc_.allocate(1);
    alloc_.construct(current, Node{value, kRed, nil_, nil_, parent});
    if (parent == nil_) {
      root_ = current;
    } else if (value < parent->value) {
      parent->left = current;
    } else {
      parent->right = current;
    }
    BalanceInsert(current);
  }
  return std::pair<iterator, bool>(iterator(current, current->parent, nil_),
                                   status);
}

template <class Key>
void set<Key>::BalanceInsert(Node* node) {
  while (node->parent && node->parent->color == kRed) {
    if (node->parent == node->parent->parent->left) {
      node = FixLeftInsert(node);
    } else {
      node = FixRightInsert(node);
    }
  }
  root_->color = kBlack;
}

template <class Key>
void set<Key>::RotateLeft(Node* node) {
  Node* temp = node->right;
  node->right = temp->left;
  if (temp->left != nil_) {
    temp->left->parent = node;
  }
  temp->parent = node->parent;
  if (node->parent == nil_) {
    root_ = temp;
  } else if (node == node->parent->left) {
    node->parent->left = temp;
  } else {
    node->parent->right = temp;
  }
  temp->left = node;
  node->parent = temp;
}

template <class Key>
void set<Key>::RotateRight(Node* node) {
  Node* temp = node->left;
  node->left = temp->right;
  if (temp->right != nil_) {
    temp->right->parent = node;
  }
  temp->parent = node->parent;
  if (node->parent == nil_) {
    root_ = temp;
  } else if (node == node->parent->left) {
    node->parent->left = temp;
  } else {
    node->parent->right = temp;
  }
  temp->right = node;
  node->parent = temp;
}

template <class Key>
typename set<Key>::Node* set<Key>::FixLeftInsert(Node* node) {
  Node* uncle = node->parent->parent->right;
  if (uncle->color == kRed) {
    node->parent->color = kBlack;
    uncle->color = kBlack;
    node->parent->parent->color = kRed;
    node = node->parent->parent;
  } else {
    if (node == node->parent->right) {
      node = node->parent;
      RotateLeft(node);
    }
    node->parent->color = kBlack;
    node->parent->parent->color = kRed;
    RotateRight(node->parent->parent);
  }
  return node;
}

template <class Key>
typename set<Key>::Node* set<Key>::FixRightInsert(Node* node) {
  Node* uncle = node->parent->parent->left;
  if (uncle->color == kRed) {
    node->parent->color = kBlack;
    uncle->color = kBlack;
    node->parent->parent->color = kRed;
    node = node->parent->parent;
  } else {
    if (node == node->parent->left) {
      node = node->parent;
      RotateRight(node);
    }
    node->parent->color = kBlack;
    node->parent->parent->color = kRed;
    RotateLeft(node->parent->parent);
  }
  return node;
}

template <class Key>
void set<Key>::erase(iterator pos) {
  Node* node_to_delete = pos.current_;
  if (node_to_delete == nil_) return;
  Node* replacement;
  Color original_color = node_to_delete->color;
  if (node_to_delete->left == nil_ || node_to_delete->right == nil_) {
    replacement = (node_to_delete->left == nil_) ? node_to_delete->right
                                                 : node_to_delete->left;
    Transplant(node_to_delete, replacement);
  } else {
    Node* temp = FindMax(node_to_delete->left);
    original_color = temp->color;
    replacement = temp->left;
    Transplant(temp, replacement);
    Transplant(node_to_delete, temp);
    temp->left = node_to_delete->left;
    node_to_delete->left->parent = temp;
    temp->right = node_to_delete->right;
    node_to_delete->right->parent = temp;
    temp->color = node_to_delete->color;
  }
  alloc_.destroy(node_to_delete);
  alloc_.deallocate(node_to_delete, 1);
  if (original_color == kBlack) {
    BalanceErase(replacement);
  }
}

template <class Key>
void set<Key>::Transplant(Node* node_to_delete, Node* replacement) {
  if (node_to_delete->parent == nil_) {
    root_ = replacement;
  } else if (node_to_delete == node_to_delete->parent->left) {
    node_to_delete->parent->left = replacement;
  } else {
    node_to_delete->parent->right = replacement;
  }
  replacement->parent = node_to_delete->parent;
}

template <class Key>
void set<Key>::BalanceErase(Node* node) {
  while (node != root_ && node->color == kBlack) {
    if (node == node->parent->left) {
      node = FixLeftErase(node);
    } else {
      node = FixRightErase(node);
    }
  }
  node->color = kBlack;
}

template <class Key>
typename set<Key>::Node* set<Key>::FixLeftErase(Node* node) {
  Node* sibling = node->parent->right;
  if (sibling->color == kRed) {
    sibling->color = kBlack;
    node->parent->color = kRed;
    RotateLeft(node->parent);
    sibling = node->parent->right;
  }
  if (sibling->left->color == kBlack && sibling->right->color == kBlack) {
    sibling->color = kRed;
    node = node->parent;
  } else {
    if (sibling->right->color == kBlack) {
      sibling->left->color = kBlack;
      sibling->color = kRed;
      RotateRight(sibling);
      sibling = node->parent->right;
    }
    sibling->color = node->parent->color;
    node->parent->color = kBlack;
    sibling->right->color = kBlack;
    RotateLeft(node->parent);
    node = root_;
  }
  return node;
}

template <class Key>
typename set<Key>::Node* set<Key>::FixRightErase(Node* node) {
  Node* sibling = node->parent->left;
  if (sibling->color == kRed) {
    sibling->color = kBlack;
    node->parent->color = kRed;
    RotateRight(node->parent);
    sibling = node->parent->left;
  }
  if (sibling->left->color == kBlack && sibling->right->color == kBlack) {
    sibling->color = kRed;
    node = node->parent;
  } else {
    if (sibling->left->color == kBlack) {
      sibling->right->color = kBlack;
      sibling->color = kRed;
      RotateLeft(sibling);
      sibling = node->parent->left;
    }
    sibling->color = node->parent->color;
    node->parent->color = kBlack;
    sibling->left->color = kBlack;
    RotateRight(node->parent);
    node = root_;
  }
  return node;
}

template <class Key>
void set<Key>::swap(set& other) noexcept {
  if (this != &other) {
    std::swap(root_, other.root_);
    std::swap(nil_, other.nil_);
  }
}

template <class Key>
void set<Key>::merge(set& other) {
  if (this != &other) {
    set<Key> replacement;
    for (auto it = other.begin(); it != other.end(); ++it) {
      auto temp = insert(*it);
      if (!temp.second) {
        replacement.insert(temp.first.current_->value);
      }
    }
    other = std::move(replacement);
  }
}

template <class Key>
typename set<Key>::iterator set<Key>::find(value_type value) {
  Node* current = root_;
  while (current != nil_ and value != current->value) {
    if (value < current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return SetIterator(current, current->parent, nil_);
}

template <class Key>
bool set<Key>::contains(const Key& key) {
  return find(key).current_ != nil_;
}

template <class Key>
template <class... Args>
vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args&&... args) {
  vector<std::pair<iterator, bool>> result;
  ((result.push_back(insert(args)), ...));
  return result;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SET_S21_SET_TPP_