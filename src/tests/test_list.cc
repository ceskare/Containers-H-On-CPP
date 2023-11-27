#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

TEST(ListTest, ConstructorDefault) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, ConstructorInitializerList) {
  s21::list<int> s21_list{1, 2, 3, 4};
  std::list<int> std_list{1, 2, 3, 4};
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, ConstructorCopy) {
  s21::list<int> s21_list{1, 2, 3, 4};
  std::list<int> std_list{1, 2, 3, 4};
  s21::list<int> s21_list_copy(s21_list);
  std::list<int> std_list_copy(std_list);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
}

TEST(ListTest, ConstructorMove) {
  s21::list<int> s21_list{1, 2, 3, 4};
  std::list<int> std_list{1, 2, 3, 4};
  s21::list<int> s21_list_copy(std::move(s21_list));
  std::list<int> std_list_copy(std::move(std_list));
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
}

TEST(ListTest, OperatorInitializerList) {
  s21::list<int> s21_list;
  s21_list = {1, 2, 3, 4};
  std::list<int> std_list;
  std_list = {1, 2, 3, 4};
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, OperatorCopy) {
  s21::list<int> s21_list{1, 2, 3, 4};
  std::list<int> std_list{1, 2, 3, 4};
  s21::list<int> s21_list_copy;
  s21_list_copy = s21_list;
  std::list<int> std_list_copy;
  std_list_copy = std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
}

TEST(ListTest, OperatorMove) {
  s21::list<int> s21_list{1, 2, 3, 4};
  std::list<int> std_list{1, 2, 3, 4};
  s21::list<int> s21_list_copy;
  s21_list_copy = std::move(s21_list);
  std::list<int> std_list_copy;
  std_list_copy = std::move(std_list);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
}

TEST(ListTest, Front) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(ListTest, Back) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListTest, Iterators) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, ConstIterators) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  auto s21_it = s21_list.cbegin();
  auto std_it = std_list.cbegin();
  for (; s21_it != s21_list.cend() && std_it != std_list.cend();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, Empty) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  EXPECT_EQ(s21_list.empty(), std_list.empty());
  s21::list<int> s21_list_empty;
  std::list<int> std_list_empty;
  EXPECT_EQ(s21_list_empty.empty(), std_list_empty.empty());
}

TEST(ListTest, Size) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, MaxSize) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  EXPECT_EQ(s21_list.max_size(), std_list.max_size());
}

TEST(ListTest, Clear) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.clear();
  std_list.clear();
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, Insert) {
  int value = 5;
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  auto s21_it = s21_list.insert(s21_list.begin(), value);
  auto std_it = std_list.insert(std_list.begin(), value);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, InsertEnd) {
  int value = 5;
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  auto s21_it = s21_list.insert(s21_list.end(), value);
  auto std_it = std_list.insert(std_list.end(), value);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, Erase) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, EraseTail) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.erase(--s21_list.end());
  std_list.erase(--std_list.end());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, PushBack) {
  int value = 5;
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.push_back(value);
  std_list.push_back(value);
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, PushFront) {
  int value = 5;
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.push_front(value);
  std_list.push_front(value);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, PushFrontEmpty) {
  int value = 5;
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.push_front(value);
  std_list.push_front(value);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, PopBack) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, PopBackSingle) {
  s21::list<int> s21_list{1};
  std::list<int> std_list{1};
  s21_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, PopFront) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListTest, Swap) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_list2{4, 5, 6};
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list2{4, 5, 6};
  s21_list.swap(s21_list2);
  std_list.swap(std_list2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list2.front(), std_list2.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list2.back(), std_list2.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());
}

TEST(ListTest, Merge) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_list2{4, 5, 6};
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list2{4, 5, 6};
  s21_list.merge(s21_list2);
  std_list.merge(std_list2);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());
}

TEST(ListTest, Splice) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_list2{4, 5, 6};
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list2{4, 5, 6};
  s21_list.splice(s21_list.cbegin(), s21_list2);
  std_list.splice(std_list.cbegin(), std_list2);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());
}

TEST(ListTest, SpliceMiddle) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_list2{4, 5, 6};
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list2{4, 5, 6};
  auto s21_it = s21_list.cbegin();
  ++s21_it;
  auto std_it = std_list.cbegin();
  ++std_it;
  s21_list.splice(s21_it, s21_list2);
  std_list.splice(std_it, std_list2);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());
}

TEST(ListTest, SpliceEnd) {
  s21::list<int> s21_list{1, 2, 3};
  s21::list<int> s21_list2{4, 5, 6};
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list2{4, 5, 6};
  s21_list.splice(s21_list.cend(), s21_list2);
  std_list.splice(std_list.cend(), std_list2);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());
}

TEST(ListTest, Reverse) {
  s21::list<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
  s21_list.reverse();
  std_list.reverse();
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, Unique) {
  s21::list<int> s21_list{1, 2, 2, 1, 3};
  std::list<int> std_list{1, 2, 2, 1, 3};
  s21_list.unique();
  std_list.unique();
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, Sort) {
  s21::list<int> s21_list{42, 17, 8, 23, 5, 15, 31, 9, 2, 11};
  std::list<int> std_list{42, 17, 8, 23, 5, 15, 31, 9, 2, 11};
  s21_list.sort();
  std_list.sort();
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, InsertMany) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 6, 7, 8, 9, 10, 2, 3, 4, 5};
  auto it = s21_list.cbegin();
  ++it;
  s21_list.insert_many(it, 6, 7, 8, 9, 10);
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, InsertManyBack) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_list.insert_many_back(6, 7, 8, 9, 10);
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ListTest, InsertManyFront) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
  s21_list.insert_many_front(6, 7, 8, 9, 10);
  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}