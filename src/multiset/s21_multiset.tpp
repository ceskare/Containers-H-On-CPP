#ifndef CPP2_S21_CONTAINERS_MULTISET_S21_MULTISET_TPP_
#define CPP2_S21_CONTAINERS_MULTISET_S21_MULTISET_TPP_

#include "s21_multiset.h"

namespace s21 {

template <class Key>
multiset<Key>::multiset() : set<Key>() {}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const& items)
    : set<Key>() {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <class Key>
multiset<Key>::multiset(const multiset& other) : set<Key>() {
  for (auto it = other.cbegin(); it != other.cend(); ++it) {
    insert(*it);
  }
}

template <class Key>
multiset<Key>::multiset(multiset&& other) : set<Key>(std::move(other)) {}

template <class Key>
multiset<Key>& multiset<Key>::operator=(
    std::initializer_list<value_type> const& items) {
  set<value_type>::clear();
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
  return *this;
}

template <class Key>
multiset<Key>& multiset<Key>::operator=(const multiset<value_type>& other) {
  set<value_type>::clear();
  for (auto it = other.cbegin(); it != other.cend(); ++it) {
    insert(*it);
  }
  return *this;
}

template <class Key>
multiset<Key>& multiset<Key>::operator=(multiset<value_type>&& other) noexcept {
  set<Key>::operator=(std::move(other));
  return *this;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::insert(
    const value_type& value) {
  Node* parent = nil_;
  Node* current = root_;
  while (current != nil_) {
    parent = current;
    if (value < current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
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
  return iterator(current, current->parent, nil_);
}

template <class Key>
void multiset<Key>::merge(multiset& other) {
  if (this != &other) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      insert(*it);
    }
    other.clear();
  }
}

template <class Key>
typename multiset<Key>::size_type multiset<Key>::count(const Key& key) {
  size_type amount = 0;
  auto it = set<value_type>::begin();
  for (; *it <= key && it != set<value_type>::end(); ++it) {
    if (*it == key) {
      ++amount;
    }
  }
  return amount;
}

template <class Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key& key) {
  auto first = lower_bound(key);
  auto second = first;
  for (; second != set<value_type>::end() && *second <= key;) {
    ++second;
  }
  return std::pair<iterator, iterator>(first, second);
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
  auto result = set<value_type>::begin();
  for (; result != set<value_type>::end() && *result < key;) {
    ++result;
  }
  return result;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
  auto result = set<value_type>::begin();
  for (; result != set<value_type>::end() && *result <= key;) {
    ++result;
  }
  return result;
}

template <class Key>
template <class... Args>
vector<typename set<Key>::iterator> multiset<Key>::insert_many(Args&&... args) {
  vector<iterator> result;
  ((result.push_back(insert(args)), ...));
  return result;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_MULTISET_S21_MULTISET_TPP_