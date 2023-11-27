#include <gtest/gtest.h>

#include <map>

#include "../s21_containers.h"

TEST(MapTest, ConstructorDefault) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, ConstructorInitializerMap) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, ConstructorCopy) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_copy(s21_map);
  std::map<int, int> std_map_copy(std_map);
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
}

TEST(MapTest, ConstructorMove) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_copy(std::move(s21_map));
  std::map<int, int> std_map_copy(std::move(std_map));
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
}

TEST(MapTest, OperatorInitializerMap) {
  s21::map<int, int> s21_map;
  s21_map = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map;
  std_map = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, OperatorCopy) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_copy;
  s21_map_copy = s21_map;
  std::map<int, int> std_map_copy;
  std_map_copy = std_map;
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
}

TEST(MapTest, OperatorMove) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_copy;
  s21_map_copy = std::move(s21_map);
  std::map<int, int> std_map_copy;
  std_map_copy = std::move(std_map);
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
}

TEST(MapTest, At) {
  const int value = 1;
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.at(value), std_map.at(value));
  const int value_throw = 4;
  EXPECT_THROW(s21_map.at(value_throw), std::out_of_range);
  EXPECT_THROW(std_map.at(value_throw), std::out_of_range);
}

TEST(MapTest, SpecifiedElement) {
  const int value = 2;
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map[value], std_map[value]);
  const int add = 5;
  s21_map[add] = add;
  std_map[add] = add;
  EXPECT_EQ(s21_map[add], std_map[add]);
}

TEST(MapTest, Iterators) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end() && std_it != std_map.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(MapTest, ConstIterators) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  auto s21_it = s21_map.cbegin();
  auto std_it = std_map.cbegin();
  for (; s21_it != s21_map.cend() && std_it != std_map.cend();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(MapTest, Empty) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.empty(), std_map.empty());
  s21::map<int, int> s21_map_empty;
  std::map<int, int> std_map_empty;
  EXPECT_EQ(s21_map_empty.empty(), std_map_empty.empty());
}

TEST(MapTest, Size) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, MaxSize) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.max_size(), std_map.max_size());
}

TEST(MapTest, Clear) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  s21_map.clear();
  std_map.clear();
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, Insert) {
  const int value = 2;
  const int key = 1;
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  auto s21_it = s21_map.insert({s21_map.at(key), value});
  auto std_it = std_map.insert({std_map.at(key), value});
  EXPECT_EQ(*s21_it.first, *std_it.first);
  EXPECT_EQ(s21_it.second, std_it.second);
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, Erase) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  s21_map.erase(s21_map.begin());
  std_map.erase(std_map.begin());
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(MapTest, Swap) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map2{{4, 4}, {5, 5}, {6, 6}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_map2{{4, 4}, {5, 5}, {6, 6}};
  s21_map.swap(s21_map2);
  std_map.swap(std_map2);
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map2.size(), std_map2.size());
}

TEST(MapTest, Merge) {
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> s21_map2{{4, 4}, {5, 5}, {6, 6}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map2{{4, 4}, {5, 5}, {6, 6}};
  s21_map.merge(s21_map2);
  std_map.merge(std_map2);
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map2.size(), std_map2.size());
}

TEST(MapTest, InsertMany) {
  s21::map<int, int> s21_map = {{1, 1}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
  std::map<int, int> std_map = {{1, 1},   {6, 6}, {7, 7}, {8, 8}, {9, 9},
                                {10, 10}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  s21_map.insert_many(std::make_pair(10, 10), std::make_pair(2, 2),
                      std::make_pair(3, 3), std::make_pair(4, 4),
                      std::make_pair(5, 5));
  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end() && std_it != std_map.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ((*s21_it).first, (*std_it).first);
    EXPECT_EQ((*s21_it).second, (*std_it).second);
  }
}

TEST(MapTest, Contains) {
  int value = 3;
  s21::map<int, int> s21_map{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map{{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.contains({value, value}), true);
}