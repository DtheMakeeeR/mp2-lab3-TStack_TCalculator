#include "../TList/LStack.h"

#include "gtest.h"

TEST(LStack, new_stack_is_empty)
{
    LStack<int> s1;
    EXPECT_EQ(1, s1.IsEmpty());
}
TEST(LStack, can_push_n_pop)
{
    LStack<int> s1;
    EXPECT_NO_THROW(s1.Push(1));
    EXPECT_NO_THROW(s1.Pop());
}
TEST(LStack, cant_pop_from_empty)
{
    LStack<int> s1;
    EXPECT_ANY_THROW(s1.Pop());
}
TEST(LStack, copied_equals)
{
    LStack<int> s1,s2;
    for (int i = 0; i < 5; i++) {
        s1.Push(i);
    }
    s2 = s1;
    EXPECT_EQ(s2, s1);
}
TEST(LStack, copied_are_different)
{
    LStack<int> s1, s2;
    for (int i = 0; i < 5; i++) {
        s1.Push(i);
    }
    s2 = s1;
    s1.Pop();
    EXPECT_NE(s2, s1);
}
TEST(LStack, peek_is_correct)
{
    LStack<int> s1;
    for (int i = 0; i < 5; i++) {
        s1.Push(i);
    }
    for (int i = 4; i >= 0; i--) {
        EXPECT_EQ(i, s1.Pop());
    }
}
TEST(LStack, not_full)
{
    LStack<int> s1;
    s1.Push(2);
    s1.Push(3);
    EXPECT_EQ(0, s1.IsFull());
}
TEST(LStack, IsEmpty)
{
    LStack<int> s1;
    EXPECT_EQ(1, s1.IsEmpty());
}
TEST(LStack, Clear)
{
    LStack<int> s1;
    s1.Push(2);
    s1.Push(3);
    s1.Clear();
    EXPECT_EQ(1, s1.IsEmpty());
}