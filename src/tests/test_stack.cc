#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

TEST(StackTest, ConstructorDefault) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, ConstructorInitializerList) {
  s21::stack<int> s21_stack{1, 2, 3, 4};
  EXPECT_EQ(s21_stack.size(), 4);
}

TEST(StackTest, ConstructorCopy) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  s21::stack<int> s21_stack_copy(s21_stack);
  std::stack<int> std_stack_copy(std_stack);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
}

TEST(StackTest, ConstructorMove) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  s21::stack<int> s21_stack_copy(std::move(s21_stack));
  std::stack<int> std_stack_copy(std::move(std_stack));
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
}

TEST(StackTest, OperatorInitializerList) {
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  s21::stack<int> s21_stack;
  s21_stack = init_list;
  EXPECT_EQ(s21_stack.size(), init_list.size());
}

TEST(StackTest, OperatorCopy) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  s21::stack<int> s21_stack_copy;
  s21_stack_copy = s21_stack;
  std::stack<int> std_stack_copy;
  std_stack_copy = std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
}

TEST(StackTest, OperatorMove) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  s21::stack<int> s21_stack_copy;
  s21_stack_copy = std::move(s21_stack);
  std::stack<int> std_stack_copy;
  std_stack_copy = std::move(std_stack);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
}

TEST(StackTest, Top) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
    EXPECT_EQ(s21_stack.top(), std_stack.top());
  }
}

TEST(StackTest, Empty) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
  s21::stack<int> s21_list_empty;
  std::stack<int> std_list_empty;
  EXPECT_EQ(s21_list_empty.empty(), std_list_empty.empty());
}

TEST(StackTest, Size) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Push) {
  int value = 5;
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(value);
  std_stack.push(value);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Pop) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Swap) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  std::initializer_list<int> init_list = {1, 2, 3};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  s21::stack<int> s21_stack2;
  std::stack<int> std_stack2;
  std::initializer_list<int> init_list2 = {4, 5};
  for (auto it = init_list2.begin(); it != init_list2.end(); ++it) {
    s21_stack.push(*it);
    std_stack.push(*it);
  }
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack2.size(), std_stack2.size());
  s21_stack.swap(s21_stack2);
  std_stack.swap(std_stack2);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack2.size(), std_stack2.size());
}

TEST(StackTest, InsertManyFront) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21_stack.insert_many_front(6, 7, 8);
  EXPECT_EQ(s21_stack.top(), 8);
}