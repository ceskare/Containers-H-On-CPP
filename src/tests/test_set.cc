#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

TEST(SetTest, ConstructorDefault) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, ConstructorInitializerList) {
  s21::set<int> s21_set{1, 2, 3, 4};
  std::set<int> std_set{1, 2, 3, 4};
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, ConstructorCopy) {
  s21::set<int> s21_set{1, 2, 3, 4};
  std::set<int> std_set{1, 2, 3, 4};
  s21::set<int> s21_set_copy(s21_set);
  std::set<int> std_set_copy(std_set);
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_copy.size(), std_set_copy.size());
}

TEST(SetTest, ConstructorMove) {
  s21::set<int> s21_set{1, 2, 3, 4};
  std::set<int> std_set{1, 2, 3, 4};
  s21::set<int> s21_set_copy(std::move(s21_set));
  std::set<int> std_set_copy(std::move(std_set));
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_copy.size(), std_set_copy.size());
}

TEST(SetTest, OperatorInitializerList) {
  s21::set<int> s21_set;
  s21_set = {1, 2, 3, 4};
  std::set<int> std_set;
  std_set = {1, 2, 3, 4};
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, OperatorCopy) {
  s21::set<int> s21_set{1, 2, 3, 4};
  std::set<int> std_set{1, 2, 3, 4};
  s21::set<int> s21_set_copy;
  s21_set_copy = s21_set;
  std::set<int> std_set_copy;
  std_set_copy = std_set;
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_copy.size(), std_set_copy.size());
}

TEST(SetTest, OperatorMove) {
  s21::set<int> s21_set{1, 2, 3, 4};
  std::set<int> std_set{1, 2, 3, 4};
  s21::set<int> s21_set_copy;
  s21_set_copy = std::move(s21_set);
  std::set<int> std_set_copy;
  std_set_copy = std::move(std_set);
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_copy.size(), std_set_copy.size());
}

TEST(SetTest, Iterators) {
  s21::set<int> s21_set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> std_set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_it = s21_set.begin();
  auto std_it = std_set.begin();
  s21_it++;
  std_it++;
  for (; s21_it != s21_set.end() && std_it != std_set.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(SetTest, IteratorsCompare) {
  s21::set<int> s21_set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> std_set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_begin = s21_set.begin();
  auto s21_end = s21_set.end();
  EXPECT_NE(s21_begin == s21_end, s21_begin != s21_end);
}

TEST(SetTest, IteratorsBackwards) {
  s21::set<int> s21_set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> std_set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto s21_it = s21_set.end();
  auto std_it = std_set.end();
  s21_it--;
  std_it--;
  for (; s21_it != s21_set.begin() && std_it != std_set.begin();
       --s21_it, --std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(SetTest, ConstIterators) {
  s21::set<int> s21_set{1, 2, 3};
  std::set<int> std_set{1, 2, 3};
  auto s21_it = s21_set.cbegin();
  auto std_it = std_set.cbegin();
  for (; s21_it != s21_set.cend() && std_it != std_set.cend();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(SetTest, Empty) {
  s21::set<int> s21_set{1, 2, 3};
  std::set<int> std_set{1, 2, 3};
  EXPECT_EQ(s21_set.empty(), std_set.empty());
  s21::set<int> s21_list_empty;
  std::set<int> std_list_empty;
  EXPECT_EQ(s21_list_empty.empty(), std_list_empty.empty());
}

TEST(SetTest, Size) {
  s21::set<int> s21_set{1, 2, 3};
  std::set<int> std_set{1, 2, 3};
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, MaxSize) {
  s21::set<double> s21_set{1, 2, 3};
  std::set<double> std_set{1, 2, 3};
  EXPECT_EQ(s21_set.max_size(), std_set.max_size());
}

TEST(SetTest, Clear) {
  s21::set<int> s21_set{1, 2, 3};
  std::set<int> std_set{1, 2, 3};
  s21_set.clear();
  std_set.clear();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, Insert) {
  int value = 5;
  s21::set<int> s21_set{1, 2, 3};
  std::set<int> std_set{1, 2, 3};
  auto s21_pair = s21_set.insert(value);
  auto std_pair = std_set.insert(value);
  EXPECT_EQ(*s21_pair.first, *s21_pair.first);
  EXPECT_EQ(std_pair.second, std_pair.second);
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, Erase) {
  s21::set<int> s21_set{1,   6,   7,   8,   9,   10,  11, 12, 13, -1,
                        -2,  14,  15,  -3,  -4,  -5,  -6, -7, -8, -9,
                        -10, -11, -12, -13, -14, -15, 2,  3,  4,  5};
  std::set<int> std_set{1,   6,   7,   8,   9,   10,  11, 12, 13, -1,
                        -2,  14,  15,  -3,  -4,  -5,  -6, -7, -8, -9,
                        -10, -11, -12, -13, -14, -15, 2,  3,  4,  5};
  std::initializer_list<int> erase_many = {
      6,  7,  8,  9,  10, 11, 12,  13,  -1,  -2,  14,  15, -3,
      -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15};
  for (auto it = erase_many.begin(); it != erase_many.end(); ++it) {
    s21_set.erase(s21_set.find(*it));
    std_set.erase(std_set.find(*it));
  }
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(SetTest, Swap) {
  s21::set<int> s21_set{1, 2, 3, 4};
  s21::set<int> s21_set2{4, 5, 6};
  std::set<int> std_set{1, 2, 3, 4};
  std::set<int> std_set2{4, 5, 6};
  s21_set.swap(s21_set2);
  std_set.swap(std_set2);
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set2.size(), std_set2.size());
}

TEST(SetTest, Merge) {
  s21::set<int> s21_set{1, 2, 3};
  s21::set<int> s21_set2{3, 4, 5, 6};
  std::set<int> std_set{1, 2, 3};
  std::set<int> std_set2{3, 4, 5, 6};
  s21_set.merge(s21_set2);
  std_set.merge(std_set2);
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set2.size(), std_set2.size());
}

TEST(SetTest, Find) {
  int value = 3;
  s21::set<int> s21_set{1, 2, 3};
  std::set<int> std_set{1, 2, 3};
  auto s21_it = s21_set.find(value);
  auto std_it = std_set.find(value);
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(SetTest, Contains) {
  int value = 3;
  s21::set<int> s21_set{1, 2, 3};
  EXPECT_EQ(s21_set.contains(value), true);
}

TEST(SetTest, InsertMany) {
  s21::set<int> s21_set = {1, 2, 3, 4, 5};
  std::set<int> std_set = {1,   6,   7,   8,   9,   10,  11, 12, 13, -1,
                           -2,  14,  15,  -3,  -4,  -5,  -6, -7, -8, -9,
                           -10, -11, -12, -13, -14, -15, 2,  3,  4,  5};
  auto it = s21_set.cbegin();
  ++it;
  s21_set.insert_many(6, 7, 8, 9, 10, 11, 12, 13, -1, -2, 14, 15, -3, -4, -5,
                      -6, -7, -8, -9, -10, -11, -12, -13, -14, -15);
  auto s21_it = s21_set.begin();
  auto std_it = std_set.begin();
  for (; s21_it != s21_set.end() && std_it != std_set.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}