#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> tmp(6), copy(tmp);
	EXPECT_EQ(tmp, copy);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> tmp(6), copy(tmp);
	EXPECT_EQ(false, &tmp[0] == &copy[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[0][1] = 3;
	EXPECT_EQ(3, m[0][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[m.GetSize() + 1][m.GetSize() + 1] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	EXPECT_EQ(m, m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v1(3), v2(3);
	v1[0][1] = 10;
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v1(4), v2(10);
	v2 = v1;
	EXPECT_EQ(v1.GetSize(), v2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v1(4), v2(10);
	v1[0][1] = 10;
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v1(4), v2(4);
	v1[0][1] = 10;
	v2 = v1;
	EXPECT_EQ(true, v1 == v2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(4);
	v[0][3] = 10;
	EXPECT_EQ(true, v == v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v1(4), v2(6);
	EXPECT_NE(v1, v2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v1(4), v2(4), res(4);
	v1[1][1] = 1;
	v2[1][2] = 2;
	res[1][1] = 1;
	res[1][2] = 2;
	EXPECT_EQ(res, v1 + v2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v1(4), v2(6);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v1(4), v2(4), res(4);
	v1[1][1] = 1;
	v2[1][1] = 11;
	v1[1][2] = 2;
	v2[1][2] = 22;
	res[1][1] = 10;
	res[1][2] = 20;
	EXPECT_EQ(res, v2 - v1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v1(4), v2(6);
	ASSERT_ANY_THROW(v1 - v2);
}

