#ifndef CPP2_S21_CONTAINERS_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_MAP_S21_MAP_H_

#include "../set/s21_set.h"

namespace s21 {

template <class Key, class T>
class map : public set<std::pair<const Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename set<value_type>::iterator;
  using const_iterator = typename set<value_type>::const_iterator;
  using size_type = size_t;

  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &other);
  map(map &&other);
  ~map() = default;

  map<Key, T> &operator=(
      std::initializer_list<value_type> const &items) override;
  map<Key, T> &operator=(const map<Key, T> &other);
  map<Key, T> &operator=(map<Key, T> &&other) noexcept;

  T &at(const Key &key);
  T &at(const Key &key) const;
  T &operator[](const Key &key);

  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

  template <class... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args);

 private:
  using typename set<value_type>::Node;
  using set<value_type>::nil_;
  using set<value_type>::root_;
  using set<value_type>::alloc_;

  iterator find(const Key &key);
};

}  // namespace s21

#include "s21_map.tpp"

#endif  // CPP2_S21_CONTAINERS_MAP_S21_MAP_H_