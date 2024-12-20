#include "../tStack/TCalc.h"
#include "../tStack/TCalc.cpp"
#include "gtest.h"
TEST(TCalc, cant_set_wrong_input)
{
    TCalc c1;
    EXPECT_ANY_THROW(c1.setInfix("2 + 1)"));
}
TEST(TCalc, can_set_and_get_postfix)
{
    TCalc c1;
    c1.setPostfix("2 2 +");
    EXPECT_EQ(c1.getPostfix(), "2 2 +");
}
TEST(TCalc, can_set_and_get_infix)
{
    TCalc c1;
    c1.setInfix("3 + 3");
    EXPECT_EQ(c1.getInfix(), "3 + 3");
}
TEST(TCalc, can_to_postfix)
{
    TCalc c1;
    c1.setInfix("2 + 2");
    c1.toPostfix();
    EXPECT_EQ(c1.getPostfix(), "2 2 + ");
}
TEST(TCalc, can_calc_unary_minus)
{
    TCalc c1;
    c1.setInfix("-5 * 4");
    EXPECT_EQ(-5*4, c1.Calc());
    c1.setInfix("10 * (-(13*4))");
    double res = c1.Calc();
    EXPECT_EQ((10*(-(13*4))), c1.Calc());
}
TEST(TCalc, can_calc_add_sub)
{
    TCalc c1;
    c1.setInfix("532.32 + 354.5454 - 762.7676");
    c1.toPostfix();
    EXPECT_EQ(532.32 + 354.5454 - 762.7676, c1.CalcPostfix());
    EXPECT_EQ(532.32 + 354.5454 - 762.7676, c1.Calc());
}
TEST(TCalc, can_calc_mul_div)
{
    TCalc c1;
    c1.setInfix("478/0.2*60/(12.5/0.5)");
    c1.toPostfix();
    EXPECT_EQ(478 / 0.2 * 60 / (12.5 / 0.5), c1.CalcPostfix());
    EXPECT_EQ(478 / 0.2 * 60 / (12.5 / 0.5), c1.Calc());
}
TEST(TCalc, can_calc_pow)
{
    TCalc c1;
    c1.setInfix("-5^10^0.2");
    c1.toPostfix();
    EXPECT_EQ(pow(pow(-5, 10), 0.2), (c1.CalcPostfix()));//ответ считает правильно 25, но не проходит тест, возможно,
    EXPECT_EQ(pow(pow(-5, 10), 0.2), (c1.Calc()));       //из-за представления числа¯\_(ツ)_/¯
}
TEST(TCalc, can_calc_functions)
{
    TCalc c1;
    c1.setInfix("sin(cos(372.81))");
    c1.toPostfix();
    //double res1 = c1.CalcPostfix(), res2 = c1.Calc(); //-0.485233
    EXPECT_EQ(sin(cos(372.81)), (c1.Calc()));    
}
TEST(TCalc, can_calc_mixed)
{
    TCalc c1;
    c1.setInfix("25^(0.5/cos(150+36))");
    c1.toPostfix();
    EXPECT_EQ(pow(25, (0.5 / cos(150 + 36))), (c1.CalcPostfix())); //округление до 4 знаков после запятой
    EXPECT_EQ(pow(25, (0.5 / cos(150 + 36))), (c1.Calc()));
}
TEST(TCalc, can_straight_calc)
{
    TCalc c1;
    //c1.setInfix("10^5");
   // EXPECT_EQ(100000, c1.Calc());
    c1.setInfix("22^3/(-0.4)");
    EXPECT_EQ(pow(22,3) / (-0.4), c1.Calc());
}


