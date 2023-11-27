#ifndef CPP2_S21_CONTAINERS_MAP_S21_MAP_TPP_
#define CPP2_S21_CONTAINERS_MAP_S21_MAP_TPP_

#include "s21_map.h"

namespace s21 {

template <class Key, class T>
map<Key, T>::map() : set<value_type>() {}

template <class Key, class T>
map<Key, T>::map(const std::initializer_list<value_type> &items)
    : set<value_type>() {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <class Key, class T>
map<Key, T>::map(const map &other) : set<value_type>(other) {}

template <class Key, class T>
map<Key, T>::map(map &&other) : set<value_type>(std::move(other)) {}

template <class Key, class T>
map<Key, T> &map<Key, T>::operator=(
    std::initializer_list<value_type> const &items) {
  set<value_type>::clear();
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
  return *this;
}

template <class Key, class T>
map<Key, T> &map<Key, T>::operator=(const map<Key, T> &other) {
  set<value_type>::operator=(other);
  return *this;
}

template <class Key, class T>
map<Key, T> &map<Key, T>::operator=(map<Key, T> &&other) noexcept {
  set<value_type>::operator=(std::move(other));
  return *this;
}

template <class Key, class T>
T &map<Key, T>::at(const Key &key) {
  auto temp = find(key);
  if (temp == set<value_type>::end()) {
    throw std::out_of_range("Key not found!");
  }
  return (*temp).second;
}

template <class Key, class T>
T &map<Key, T>::at(const Key &key) const {
  auto temp = find(key);
  if (temp == set<value_type>::end()) {
    throw std::out_of_range("Key not found!");
  }
  return (*temp).second;
}

template <class Key, class T>
T &map<Key, T>::operator[](const Key &key) {
  auto iterator = insert(key, mapped_type{}).first;
  return (*iterator).second;
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type &value) {
  bool status = true;
  Node *parent = nil_;
  Node *current = root_;
  while (current != nil_) {
    parent = current;
    if (value.first < current->value.first) {
      current = current->left;
    } else if (value.first > current->value.first) {
      current = current->right;
    } else {
      break;
    }
  }
  if (parent != nil_ && parent->value.first == value.first) {
    status = false;
  } else {
    current = alloc_.allocate(1);
    alloc_.construct(current,
                     Node{value, set<value_type>::kRed, nil_, nil_, parent});
    if (parent == nil_) {
      root_ = current;
    } else if (value < parent->value) {
      parent->left = current;
    } else {
      parent->right = current;
    }
    set<value_type>::BalanceInsert(current);
  }
  return std::make_pair(iterator(current, current->parent, nil_), status);
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  std::pair<const Key, T> temp(key, obj);
  return insert(temp);
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  iterator temp = find(key);
  if (temp.current_ == nil_) {
    return insert(key, obj);
  }
  temp.current_->value.second = obj;
  std::pair<iterator, bool> result(temp, false);
  return result;
}

template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) {
  typename set<value_type>::Node *current = root_;
  while (current != nil_ and key != current->value.first) {
    if (key < current->value.first) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return iterator(current, current->parent, nil_);
}

template <class Key, class T>
template <class... Args>
vector<std::pair<typename map<Key, T>::iterator, bool>> map<Key, T>::insert_many(
    Args &&...args) {
  vector<std::pair<iterator, bool>> result;
  ((result.push_back(insert(args)), ...));
  return result;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_MAP_S21_MAP_TPP_