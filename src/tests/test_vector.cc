#include <gtest/gtest.h>

#include <vector>

#include "../s21_containers.h"

TEST(VectorTest, ConstructorDefault) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, ConstructorExplicit) {
  s21::vector<int> s21_vector(4);
  std::vector<int> std_vector(4);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, ConstructorInitializerList) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  EXPECT_EQ(s21_vector.size(), 4);
  for (auto i = s21_vector.begin(); i != s21_vector.end(); ++i) {
    EXPECT_EQ(s21_vector[*i - 1], *i);
  }
}

TEST(VectorTest, ConstructorCopy) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector_copy(s21_vector);
  std::vector<int> std_vector_copy(std_vector);

  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_vector_copy[i], s21_vector_copy[i]);
  }
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector_copy.size(), std_vector_copy.size());
}

TEST(VectorTest, ConstructorMove) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector_copy(std::move(s21_vector));
  std::vector<int> std_vector_copy(std::move(std_vector));
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_vector_copy[i], s21_vector_copy[i]);
  }
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector_copy.size(), std_vector_copy.size());
}

TEST(VectorTest, OperatorInitializerList) {
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  s21::vector<int> s21_vector;
  s21_vector = init_list;
  auto it = init_list.begin();
  for (size_t i = 0; i != 4 && it != init_list.end(); ++i, ++it) {
    EXPECT_EQ(s21_vector[i], *it);
  }
  EXPECT_EQ(s21_vector.size(), init_list.size());
}

TEST(VectorTest, OperatorCopy) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector_copy;
  s21_vector_copy = s21_vector;
  std::vector<int> std_vector_copy;
  std_vector_copy = std_vector;
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_vector_copy[i], s21_vector_copy[i]);
  }
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector_copy.size(), std_vector_copy.size());
}

TEST(VectorTest, OperatorMove) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector_copy;
  s21_vector_copy = std::move(s21_vector);
  std::vector<int> std_vector_copy;
  std_vector_copy = std::move(std_vector);
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_vector_copy[i], s21_vector_copy[i]);
  }
}

TEST(VectorTest, SpecifiedElement) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
}

TEST(VectorTest, At) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_vector.at(i), std_vector.at(i));
  }
  const int value_throw = 5;
  EXPECT_THROW(s21_vector.at(value_throw), std::out_of_range);
  EXPECT_THROW(std_vector.at(value_throw), std::out_of_range);
}

TEST(VectorTest, Front) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  EXPECT_EQ(s21_vector.front(), std_vector.front());
}

TEST(VectorTest, Back) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  EXPECT_EQ(s21_vector.back(), std_vector.back());
}

TEST(VectorTest, Data) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  auto data_s21 = s21_vector.data();
  auto data_std = std_vector.data();
  for (size_t i = 0; i != 4; ++i, ++data_s21, ++data_std) {
    EXPECT_EQ(*data_s21, *data_std);
  }
}

TEST(VectorTest, ConstData) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  auto data_s21 = s21_vector.data();
  auto data_std = std_vector.data();
  for (size_t i = 0; i != 4; ++i, ++data_s21, ++data_std) {
    EXPECT_EQ(*data_s21, *data_std);
  }
}

TEST(VectorTest, Iterators) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  auto s21_it = s21_vector.begin();
  auto std_it = std_vector.begin();
  for (; s21_it != s21_vector.end() && std_it != std_vector.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(VectorTest, ConstIterators) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  auto s21_it = s21_vector.cbegin();
  auto std_it = std_vector.cbegin();
  for (; s21_it != s21_vector.cend() && std_it != std_vector.cend();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(VectorTest, Empty) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
  s21::vector<int> s21_vector_empty;
  std::vector<int> std_vector_empty;
  EXPECT_EQ(s21_vector_empty.empty(), std_vector_empty.empty());
}

TEST(VectorTest, Size) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, MaxSize) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  EXPECT_EQ(s21_vector.max_size(), std_vector.max_size());
}

TEST(VectorTest, Reserve) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.reserve(100);
  std_vector.reserve(100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, ShrinkToFit) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21_vector.reserve(100);
  std_vector.reserve(100);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, Clear) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21_vector.clear();
  std_vector.clear();
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
  EXPECT_EQ(std_vector.size(), s21_vector.size());
  EXPECT_EQ(std_vector.capacity(), s21_vector.capacity());
}

TEST(VectorTest, Insert) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  auto it_21 = s21_vector.begin();
  it_21 = s21_vector.insert(it_21, 0);
  auto it_std = std_vector.begin();
  it_std = std_vector.insert(it_std, 0);
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
  EXPECT_EQ(std_vector.size(), s21_vector.size());
  EXPECT_EQ(*it_21, *it_std);
  EXPECT_EQ(std_vector.capacity(), s21_vector.capacity());
}

TEST(VectorTest, Erase) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21_vector.erase(s21_vector.begin());
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
  EXPECT_EQ(std_vector.size(), s21_vector.size());
  EXPECT_EQ(std_vector.capacity(), s21_vector.capacity());
}

TEST(VectorTest, PushBack) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21_vector.push_back(5);
  std_vector.push_back(5);

  for (size_t i = 0; i != 5; ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
  EXPECT_EQ(std_vector.size(), s21_vector.size());
  EXPECT_EQ(std_vector.capacity(), s21_vector.capacity());
}

TEST(VectorTest, PopBack) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i != 3; ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
  EXPECT_EQ(std_vector.size(), s21_vector.size());
  EXPECT_EQ(std_vector.capacity(), s21_vector.capacity());
}

TEST(VectorTest, Swap) {
  s21::vector<int> s21_vector{1, 2, 3, 4};
  std::vector<int> std_vector{1, 2, 3, 4};
  s21::vector<int> s21_vector_2{5, 6, 7, 8};
  std::vector<int> std_vector_2{5, 6, 7, 8};
  s21_vector.swap(s21_vector_2);
  std_vector.swap(std_vector_2);
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_vector_2[i], s21_vector_2[i]);
    EXPECT_EQ(std_vector[i], s21_vector[i]);
  }
}

TEST(VectorTest, InsertMany) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 10, 9, 8, 7, 6, 2, 3, 4, 5};
  auto it = s21_vector.cbegin();
  ++it;
  s21_vector.insert_many(it, 6, 7, 8, 9, 10);
  auto s21_it = s21_vector.begin();
  auto std_it = std_vector.begin();
  for (; s21_it != s21_vector.end() && std_it != std_vector.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(VectorTest, InsertManyBack) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.insert_many_back(6, 7, 8, 9, 10);
  for (size_t i = 0; i != 10; ++i) {
    EXPECT_EQ(std_vector[i], s21_vector[i]);
  }
}