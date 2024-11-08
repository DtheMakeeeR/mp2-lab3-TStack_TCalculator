#include "../tStack/TCalc.h"

#include "gtest.h"
TEST(TStack, cant_set_wrong_input)
{
    TCalc c1;
    EXPECT_ANY_THROW(c1.setInfix("2 + 1)"));
}
