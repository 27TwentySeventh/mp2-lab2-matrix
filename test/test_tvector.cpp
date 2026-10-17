#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v(10);
  v[5] = 25;
  TDynamicVector<int> v1(v);
  ASSERT_EQ(true, v==v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> v(10);
  v[0] = 10;
  ASSERT_EQ(10, v[0]);
  TDynamicVector<int> v1(v);
  v1[0] = 11;
  ASSERT_EQ(11, v1[0]); ASSERT_EQ(10, v[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(v[-3] = 4);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(v[4] = 4);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> v(4);
  v[1]=7;
  v = v;
  EXPECT_EQ(7,v[1]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  TDynamicVector<int> a(3), b(3);
  b[1]=9;
  a = b;
  EXPECT_TRUE(a==b);
  b[1]=0;
  EXPECT_EQ(9,a[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> a(3), b(5);
  a = b;
  EXPECT_EQ(5,a.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  TDynamicVector<int> a(3), b(5);
  b[1]=9;
  a=b;
  EXPECT_TRUE(a==b);
  b[1]=0;
  EXPECT_EQ(9,a[1]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  TDynamicVector<int> a(3), b(3);
  a[1] = 9; b[1] = 9;
  EXPECT_TRUE(a==b);
  b[0]=1;
  EXPECT_TRUE(a!=b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> a(3);
  a[1] = 9;
  EXPECT_TRUE(a==a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> a(3), b(4);
  EXPECT_FALSE(a==b);
  EXPECT_TRUE(a!=b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  TDynamicVector<int> a(3), b(3);
  a[0] = 9; a[2] = 24;
  b = a+1;
  EXPECT_EQ(9, a[0]); EXPECT_EQ(0, a[1]); EXPECT_EQ(24, a[2]);
  EXPECT_EQ(10, b[0]); EXPECT_EQ(1, b[1]); EXPECT_EQ(25, b[2]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  TDynamicVector<int> a(3), b(3);
  a[0] = 9; a[2] = 24;
  b = a-1;
  EXPECT_EQ(9, a[0]); EXPECT_EQ(0, a[1]); EXPECT_EQ(24, a[2]);
  EXPECT_EQ(8, b[0]); EXPECT_EQ(-1, b[1]); EXPECT_EQ(23, b[2]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  TDynamicVector<int> a(3), b(3);
  a[0] = 10; a[2] = 20;
  b = a*2;
  EXPECT_EQ(10, a[0]); EXPECT_EQ(0, a[1]); EXPECT_EQ(20, a[2]);
  EXPECT_EQ(20, b[0]); EXPECT_EQ(0, b[1]); EXPECT_EQ(40, b[2]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  TDynamicVector<int> a(3), b(3), p(3);
  a[0] = 10; a[2] = 20;
  b[1] = 5; b[2] = 10;
  p = a+b;
  EXPECT_EQ(10, a[0]); EXPECT_EQ(0, a[1]); EXPECT_EQ(20, a[2]);
  EXPECT_EQ(0, b[0]); EXPECT_EQ(5, b[1]); EXPECT_EQ(10, b[2]);
  EXPECT_EQ(10, p[0]); EXPECT_EQ(5, p[1]); EXPECT_EQ(30, p[2]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(3), b(4);
  EXPECT_ANY_THROW(a+b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  TDynamicVector<int> a(3), b(3), p(3);
  a[0] = 10; a[2] = 20;
  b[1] = 5; b[2] = 10;
  p = a-b;
  EXPECT_EQ(10, a[0]); EXPECT_EQ(0, a[1]); EXPECT_EQ(20, a[2]);
  EXPECT_EQ(0, b[0]); EXPECT_EQ(5, b[1]); EXPECT_EQ(10, b[2]);
  EXPECT_EQ(10, p[0]); EXPECT_EQ(-5, p[1]); EXPECT_EQ(10, p[2]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(3), b(4);
  EXPECT_ANY_THROW(a-b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  TDynamicVector<int> a(3), b(3);
  a[0] = 10; a[2] = 20;
  b[0] = 1; b[1] = 5; b[2] = 10;
  int p = a*b;
  EXPECT_EQ(10, a[0]); EXPECT_EQ(0, a[1]); EXPECT_EQ(20, a[2]);
  EXPECT_EQ(1, b[0]); EXPECT_EQ(5, b[1]); EXPECT_EQ(10, b[2]);
  EXPECT_EQ(210, p);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(3), b(4);
  EXPECT_ANY_THROW(a*b);
}

