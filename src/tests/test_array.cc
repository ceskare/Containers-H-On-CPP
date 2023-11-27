#include <gtest/gtest.h>

#include <array>

#include "../s21_containersplus.h"

TEST(ArrayTest, ConstructorDefault) {
  s21::array<int, 3> s21_array;
  std::array<int, 3> std_array;
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(ArrayTest, ConstructorInitializerList) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  EXPECT_EQ(s21_array.size(), 4);
  for (auto i = s21_array.begin(); i != s21_array.end(); ++i) {
    EXPECT_EQ(s21_array[*i - 1], *i);
  }
}

TEST(ArrayTest, ConstructorCopy) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  s21::array<int, 4> s21_array_copy(s21_array);
  std::array<int, 4> std_array_copy(std_array);

  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_array_copy[i], s21_array_copy[i]);
  }
  EXPECT_EQ(s21_array.size(), std_array.size());
  EXPECT_EQ(s21_array_copy.size(), std_array_copy.size());
}

TEST(ArrayTest, ConstructorMove) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  s21::array<int, 4> s21_array_copy(std::move(s21_array));
  std::array<int, 4> std_array_copy(std::move(std_array));
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_array_copy[i], s21_array_copy[i]);
  }
  EXPECT_EQ(s21_array.size(), std_array.size());
  EXPECT_EQ(s21_array_copy.size(), std_array_copy.size());
}

TEST(ArrayTest, OperatorInitializerList) {
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  s21::array<int, 4> s21_array;
  s21_array = init_list;
  auto it = init_list.begin();
  for (size_t i = 0; i != 4 && it != init_list.end(); ++i, ++it) {
    EXPECT_EQ(s21_array[i], *it);
  }
  EXPECT_EQ(s21_array.size(), init_list.size());
  std::initializer_list<int> init_trow = {1, 2, 3, 4, 5};
  EXPECT_THROW(s21_array = init_trow, std::out_of_range);
}

TEST(ArrayTest, OperatorCopy) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};

  s21::array<int, 4> s21_array_copy;
  s21_array_copy = s21_array;
  std::array<int, 4> std_array_copy;
  std_array_copy = std_array;
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_array_copy[i], s21_array_copy[i]);
  }
  EXPECT_EQ(s21_array.size(), std_array.size());
  EXPECT_EQ(s21_array_copy.size(), std_array_copy.size());
}

TEST(ArrayTest, OperatorMove) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};

  s21::array<int, 4> s21_array_copy;
  s21_array_copy = std::move(s21_array);
  std::array<int, 4> std_array_copy;
  std_array_copy = std::move(std_array);
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_array_copy[i], s21_array_copy[i]);
  }
  EXPECT_EQ(s21_array_copy.size(), std_array.size());
}

TEST(ArrayTest, SpecifiedElement) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_array[i], std_array[i]);
  }
}

TEST(ArrayTest, At) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(s21_array.at(i), std_array.at(i));
  }
  const int value_throw = 5;
  EXPECT_THROW(s21_array.at(value_throw), std::out_of_range);
  EXPECT_THROW(std_array.at(value_throw), std::out_of_range);
}

TEST(ArrayTest, Front) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  EXPECT_EQ(s21_array.front(), std_array.front());
}

TEST(ArrayTest, Back) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  EXPECT_EQ(s21_array.back(), std_array.back());
}

TEST(ArrayTest, Data) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  auto data_s21 = s21_array.data();
  auto data_std = std_array.data();
  for (size_t i = 0; i != 4; ++i, ++data_s21, ++data_std) {
    EXPECT_EQ(*data_s21, *data_std);
  }
}

TEST(ArrayTest, ConstData) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  auto data_s21 = s21_array.data();
  auto data_std = std_array.data();
  for (size_t i = 0; i != 4; ++i, ++data_s21, ++data_std) {
    EXPECT_EQ(*data_s21, *data_std);
  }
}

TEST(ArrayTest, Iterators) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  auto s21_it = s21_array.begin();
  auto std_it = std_array.begin();
  for (; s21_it != s21_array.end() && std_it != std_array.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ArrayTest, ConstIterators) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  auto s21_it = s21_array.cbegin();
  auto std_it = std_array.cbegin();
  for (; s21_it != s21_array.cend() && std_it != std_array.cend();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

TEST(ArrayTest, Empty) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  EXPECT_EQ(s21_array.empty(), std_array.empty());
  s21::array<int, 0> s21_array_empty;
  std::array<int, 0> std_array_empty;
  EXPECT_EQ(s21_array_empty.empty(), std_array_empty.empty());
}

TEST(ArrayTest, Size) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(ArrayTest, MaxSize) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  EXPECT_EQ(s21_array.max_size(), std_array.max_size());
}

TEST(ArrayTest, Swap) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  s21::array<int, 4> s21_array_2{5, 6, 7, 8};
  std::array<int, 4> std_array_2{5, 6, 7, 8};
  s21_array.swap(s21_array_2);
  std_array.swap(std_array_2);
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_array_2[i], s21_array_2[i]);
    EXPECT_EQ(std_array[i], s21_array[i]);
  }
}

TEST(ArrayTest, Fill) {
  s21::array<int, 4> s21_array;
  std::array<int, 4> std_array;
  s21_array.fill(1);
  std_array.fill(1);
  for (size_t i = 0; i != 4; ++i) {
    EXPECT_EQ(std_array[i], s21_array[i]);
  }
}