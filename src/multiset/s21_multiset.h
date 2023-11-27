#ifndef CPP2_S21_CONTAINERS_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_MULTISET_S21_MULTISET_H_

#include "../set/s21_set.h"

namespace s21 {

template <class Key>
class multiset : public set<Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = Key&;
  using const_reference = const Key&;
  using iterator = typename set<value_type>::iterator;
  using const_iterator = typename set<value_type>::const_iterator;
  using size_type = size_t;

  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& other);
  multiset(multiset&& other);
  ~multiset() = default;

  multiset<value_type>& operator=(
      std::initializer_list<value_type> const& items);
  multiset<value_type>& operator=(const multiset<value_type>& other);
  multiset<value_type>& operator=(multiset<value_type>&& other) noexcept;

  iterator insert(const value_type& value);

  void merge(multiset& other);

  size_type count(const Key& key);
  std::pair<iterator, iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);

  template <class... Args>
  vector<iterator> insert_many(Args&&... args);

 private:
  using typename set<value_type>::Node;
  using set<value_type>::nil_;
  using set<value_type>::root_;
  using set<value_type>::alloc_;
};

}  // namespace s21

#include "s21_multiset.tpp"

#endif  // CPP2_S21_CONTAINERS_MULTISET_S21_MULTISET_H_