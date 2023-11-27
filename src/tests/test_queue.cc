#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

TEST(QueueTest, ConstructorDefault) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueTest, ConstructorInitializerList) {
  s21::queue<int> s21_queue{1, 2, 3, 4};
  EXPECT_EQ(s21_queue.size(), 4);
}

TEST(QueueTest, ConstructorCopy) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  s21::queue<int> s21_queue_copy(s21_queue);
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue_copy.size(), std_queue_copy.size());
}

TEST(QueueTest, ConstructorMove) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  s21::queue<int> s21_queue_copy(std::move(s21_queue));
  std::queue<int> std_queue_copy(std::move(std_queue));
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue_copy.size(), std_queue_copy.size());
}

TEST(QueueTest, OperatorInitializerList) {
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  s21::queue<int> s21_queue;
  s21_queue = init_list;
  EXPECT_EQ(s21_queue.size(), init_list.size());
}

TEST(QueueTest, OperatorCopy) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  s21::queue<int> s21_queue_copy;
  s21_queue_copy = s21_queue;
  std::queue<int> std_queue_copy;
  std_queue_copy = std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue_copy.size(), std_queue_copy.size());
}

TEST(QueueTest, OperatorMove) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  s21::queue<int> s21_queue_copy;
  s21_queue_copy = std::move(s21_queue);
  std::queue<int> std_queue_copy;
  std_queue_copy = std::move(std_queue);
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue_copy.size(), std_queue_copy.size());
}

TEST(QueueTest, Back) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
    EXPECT_EQ(s21_queue.back(), std_queue.back());
  }
}

TEST(QueueTest, Front) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
    EXPECT_EQ(s21_queue.front(), std_queue.front());
  }
}

TEST(QueueTest, Empty) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
  s21::queue<int> s21_list_empty;
  std::queue<int> std_list_empty;
  EXPECT_EQ(s21_list_empty.empty(), std_list_empty.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  int value = 5;
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(value);
  std_queue.push(value);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueTest, Pop) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueTest, Swap) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std::initializer_list<int> init_list = {1, 2, 3};
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  s21::queue<int> s21_queue2;
  std::queue<int> std_queue2;
  std::initializer_list<int> init_list2 = {4, 5};
  for (auto it = init_list2.begin(); it != init_list2.end(); ++it) {
    s21_queue.push(*it);
    std_queue.push(*it);
  }
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue2.size(), std_queue2.size());
  s21_queue.swap(s21_queue2);
  std_queue.swap(std_queue2);
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue2.size(), std_queue2.size());
}

TEST(QueueTest, InsertManyBack) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21_queue.insert_many_back(6, 7, 8);
  EXPECT_EQ(s21_queue.back(), 8);
}