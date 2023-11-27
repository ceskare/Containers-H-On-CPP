#include <gtest/gtest.h>

#include <set>

#include "../s21_containersplus.h"

TEST(MultimultisetTest, ConstructorDefault) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, ConstructorInitializerList) {
  s21::multiset<int> s21_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, ConstructorCopy) {
  s21::multiset<int> s21_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  s21::multiset<int> s21_multiset_copy(s21_multiset);
  std::multiset<int> std_multiset_copy(std_multiset);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
}

TEST(MultimultisetTest, ConstructorMove) {
  s21::multiset<int> s21_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  s21::multiset<int> s21_multiset_copy(std::move(s21_multiset));
  std::multiset<int> std_multiset_copy(std::move(std_multiset));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
}

TEST(MultimultisetTest, OperatorInitializerList) {
  s21::multiset<int> s21_multiset;
  s21_multiset = {1, 2, 2, 2, 2, 2, 3, 5, 5};
  std::multiset<int> std_multiset;
  std_multiset = {1, 2, 2, 2, 2, 2, 3, 5, 5};
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, OperatorCopy) {
  s21::multiset<int> s21_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  s21::multiset<int> s21_multiset_copy;
  s21_multiset_copy = s21_multiset;
  std::multiset<int> std_multiset_copy;
  std_multiset_copy = std_multiset;
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
}

TEST(MultimultisetTest, OperatorMove) {
  s21::multiset<int> s21_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 2, 2, 2, 2, 3, 5, 5};
  s21::multiset<int> s21_multiset_copy;
  s21_multiset_copy = std::move(s21_multiset);
  std::multiset<int> std_multiset_copy;
  std_multiset_copy = std::move(std_multiset);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
}

TEST(MultimultisetTest, Iterators) {
  s21::multiset<int> s21_multiset{1, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 3, 5, 5};
  auto s21_it = s21_multiset.begin();
  auto std_it = std_multiset.begin();
  for (; s21_it != s21_multiset.end() && std_it != std_multiset.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(MultimultisetTest, ConstIterators) {
  s21::multiset<int> s21_multiset{1, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 3, 5, 5};
  auto s21_it = s21_multiset.cbegin();
  auto std_it = std_multiset.cbegin();
  for (; s21_it != s21_multiset.cend() && std_it != std_multiset.cend();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(MultimultisetTest, Empty) {
  s21::multiset<int> s21_multiset{1, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 3, 5, 5};
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
  s21::multiset<int> s21_list_empty;
  std::multiset<int> std_list_empty;
  EXPECT_EQ(s21_list_empty.empty(), std_list_empty.empty());
}

TEST(MultimultisetTest, Size) {
  s21::multiset<int> s21_multiset{1, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 3, 5, 5};
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, MaxSize) {
  s21::multiset<double> s21_multiset{1, 2, 3, 2, 2};
  std::multiset<double> std_multiset{1, 2, 3, 2, 2};
  EXPECT_EQ(s21_multiset.max_size(), std_multiset.max_size());
}

TEST(MultimultisetTest, Clear) {
  s21::multiset<int> s21_multiset{1, 2, 3, 3, 3};
  std::multiset<int> std_multiset{1, 2, 3, 3, 3};
  s21_multiset.clear();
  std_multiset.clear();
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, Insert) {
  int value = 5;
  s21::multiset<int> s21_multiset{1, 2, 3, 2};
  std::multiset<int> std_multiset{1, 2, 3, 2};
  auto s21_pair = s21_multiset.insert(value);
  auto std_pair = std_multiset.insert(value);
  EXPECT_EQ(*s21_pair, *std_pair);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, Erase) {
  s21::multiset<int> s21_multiset{1, 2, 3, 5, 5};
  std::multiset<int> std_multiset{1, 2, 3, 5, 5};
  s21_multiset.erase(s21_multiset.begin());
  std_multiset.erase(std_multiset.begin());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(MultimultisetTest, Swap) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 4};
  s21::multiset<int> s21_multiset2{4, 5, 6};
  std::multiset<int> std_multiset{1, 2, 3, 4, 4};
  std::multiset<int> std_multiset2{4, 5, 6};
  s21_multiset.swap(s21_multiset2);
  std_multiset.swap(std_multiset2);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset2.size(), std_multiset2.size());
}

TEST(MultimultisetTest, Merge) {
  s21::multiset<int> s21_multiset{1, 2, 3, 3};
  s21::multiset<int> s21_multiset2{3, 4, 5, 6};
  std::multiset<int> std_multiset{1, 2, 3, 3};
  std::multiset<int> std_multiset2{3, 4, 5, 6};
  s21_multiset.merge(s21_multiset2);
  std_multiset.merge(std_multiset2);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset2.size(), std_multiset2.size());
}

TEST(MultimultisetTest, Find) {
  int value = 3;
  s21::multiset<int> s21_multiset{1, 1, 2, 3};
  std::multiset<int> std_multiset{1, 1, 2, 3};
  auto s21_it = s21_multiset.find(value);
  auto std_it = std_multiset.find(value);
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(MultimultisetTest, Contains) {
  int value = 3;
  s21::multiset<int> s21_multiset{1, 2, 3, 5, 5};
  EXPECT_EQ(s21_multiset.contains(value), true);
}

TEST(MultimultisetTest, InsertMany) {
  s21::multiset<int> s21_multiset = {1, 2, 3, 4, 5};
  std::multiset<int> std_multiset = {1, 6, 7, 8, 9, 10, 2, 3, 4, 5};
  auto it = s21_multiset.cbegin();
  ++it;
  s21_multiset.insert_many(6, 7, 8, 9, 10);
  auto s21_it = s21_multiset.begin();
  auto std_it = std_multiset.begin();
  for (; s21_it != s21_multiset.end() && std_it != std_multiset.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(MultimultisetTest, Count) {
  int value = 3;
  s21::multiset<int> s21_multiset{1, 2, 3, 3, 3, 2};
  std::multiset<int> std_multiset{1, 2, 3, 3, 3, 2};
  EXPECT_EQ(s21_multiset.count(value), std_multiset.count(value));
}

TEST(MultimultisetTest, EqualRange) {
  int value = 2;
  s21::multiset<int> s21_multiset{1, 2, 3, 3, 3, 2};
  std::multiset<int> std_multiset{1, 2, 3, 3, 3, 2};
  EXPECT_EQ(*s21_multiset.equal_range(value).first,
            *std_multiset.equal_range(value).first);
  EXPECT_EQ(*s21_multiset.equal_range(value).second,
            *std_multiset.equal_range(value).second);
}

TEST(MultimultisetTest, LowerBound) {
  int value = 2;
  s21::multiset<int> s21_multiset{1, 2, 3, 3, 3, 2};
  std::multiset<int> std_multiset{1, 2, 3, 3, 3, 2};
  EXPECT_EQ(*s21_multiset.lower_bound(value), *std_multiset.lower_bound(value));
}

TEST(MultimultisetTest, UpperBound) {
  int value = 2;
  s21::multiset<int> s21_multiset{1, 2, 3, 3, 3, 2};
  std::multiset<int> std_multiset{1, 2, 3, 3, 3, 2};
  EXPECT_EQ(*s21_multiset.upper_bound(value), *std_multiset.upper_bound(value));
}