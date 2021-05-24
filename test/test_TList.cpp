#include "List.h"
#include "ListIter.h"
#include "../gtest/gtest.h"

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> t);
}
TEST(TList, can_add_to_list_first) {
	TList<int> t;
	ASSERT_NO_THROW(t.InsFirst(1));
}
TEST(TList, can_add_to_list_last) {
	TList<int> t;
	t.InsFirst(1);
	ASSERT_NO_THROW(t.InsLast(2));
}
TEST(TList, can_add_to_list) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	ASSERT_NO_THROW(t.Ins(t.GetFirst(), 1));
}
TEST(TList, can_get_from_list_first) {
	TList<int> t;
	t.InsFirst(1);
	EXPECT_EQ(t.GetFirst()->GetData(), 1);
}
TEST(TList, can_get_from_list_last) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	EXPECT_EQ(t.GetLast()->GetData(), 2);
}
TEST(TList, throws_when_ins_element_not_found) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	ASSERT_ANY_THROW(t.Ins(new TListElem<int>(3), 1));
}
TEST(TList, can_get_count) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	EXPECT_EQ(t.GetSize(), 2);
}
TEST(TList, can_delete_first) {
	TList<int> t, t1;
	t.InsFirst(1);
	t.InsLast(2);
	t.InsLast(3);
	t1.InsLast(2);
	t1.InsLast(3);
	t.DelFirst();
	EXPECT_EQ(t, t1);
}
TEST(TList, can_delete_last) {
	TList<int> t, t1;
	t.InsFirst(1);
	t.InsLast(2);
	t.InsLast(3);
	t1.InsFirst(1);
	t1.InsLast(2);
	t.DelLast();
	EXPECT_EQ(t, t1);
}
TEST(TList, throws_when_delete_from_empty_list) {
	TList<int> t;
	ASSERT_ANY_THROW(t.DelFirst());
}
TEST(TList, throws_when_delete_from_empty_list_2) {
	TList<int> t;
	ASSERT_ANY_THROW(t.DelLast());
}
TEST(TList, can_delete_with_random_access) {
	TList<int> t, t1;
	t.InsFirst(1);
	t.InsLast(2);
	TListElem<int>* e = t.GetLast();
	t.InsLast(3);
	t1.InsFirst(1);
	t1.InsLast(3);
	t.Del(e);
	EXPECT_EQ(t, t1);
}
TEST(TList, can_copy_list) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	TList<int> t1(t);
	EXPECT_EQ(t, t1);
}
TEST(TList, can_copy_list_2) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	TList<int> t1;
	t1 = t;
	EXPECT_EQ(t, t1);
}
TEST(TList, can_use_file_input_output) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	std::ofstream fout;
	fout.open("file.txt");
	fout << t;
	fout.close();

	TList<int> t1;
	std::ifstream fin;
	fin.open("file.txt");
	fin >> t1;
	fin.close();
	EXPECT_EQ(t, t1);
}
TEST(TList, can_get_didided_by_k) {
	TList<int> t;
	t.InsFirst(1);
	t.InsLast(2);
	t.InsLast(3);
	t.InsLast(6);
	TList<int> t1, t2;
	t1.InsFirst(2);
	t1.InsLast(6);
	t2 = t.DividedByK(2);
	EXPECT_EQ(t1, t2);
}
