#include "../MaximumValueOfKCoinsFromPiles.h"
#include "gtest/gtest.h"

class ParameterizedMaximumValueOfKCoinsFromPiles : public ::testing::TestWithParam<std::tuple<vector<vector<int>>, int, int>> {};
TEST_P(ParameterizedMaximumValueOfKCoinsFromPiles, BruteForce)
{
    vector<vector<int>> piles = std::get<0>(GetParam());
    int k = std::get<1>(GetParam());
    int expected = std::get<2>(GetParam());

    int actualBruteForce = Solution1().maxValueOfCoins(piles, k);
    ASSERT_EQ(expected, actualBruteForce);
}
TEST_P(ParameterizedMaximumValueOfKCoinsFromPiles, Memo)
{
    vector<vector<int>> piles = std::get<0>(GetParam());
    int k = std::get<1>(GetParam());
    int expected = std::get<2>(GetParam());

    int actualMemo = Solution2().maxValueOfCoins(piles, k);
    ASSERT_EQ(expected, actualMemo);
}
INSTANTIATE_TEST_CASE_P(
    MaximumValueOfKCoinsFromPiles,
    ParameterizedMaximumValueOfKCoinsFromPiles,
    ::testing::Values(
        std::make_tuple(vector<vector<int>>{{1,100,3}, {7,8,9}}, 2, 101),
        std::make_tuple(vector<vector<int>>{{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}}, 7, 706)
    )
);

