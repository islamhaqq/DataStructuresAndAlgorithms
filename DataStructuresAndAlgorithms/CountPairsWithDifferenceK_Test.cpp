#include "CountPairsWithDifferenceK.h"
#include "gtest/gtest.h"

class ParameterizedCountPairsWithDifferenceK : public ::testing::TestWithParam<std::tuple<vector<int>, int, int>> {};
TEST_P(ParameterizedCountPairsWithDifferenceK, HashMap)
{
    auto [array, k, expected] = GetParam();
    int actualBruteForce = Solution().CountPairs(array, k);
    ASSERT_EQ(expected, actualBruteForce);
}
TEST_P(ParameterizedCountPairsWithDifferenceK, WithSorted)
{
    auto [array, k, expected] = GetParam();
    int actualBruteForce = Solution().WithSort(array, k);
    ASSERT_EQ(expected, actualBruteForce);
}
TEST_P(ParameterizedCountPairsWithDifferenceK, BruteForce)
{
    auto [array, k, expected] = GetParam();
    int actualBruteForce = Solution().BruteForce(array, k);
    ASSERT_EQ(expected, actualBruteForce);
}
INSTANTIATE_TEST_CASE_P(
    CountPairsWithDifferenceK,
    ParameterizedCountPairsWithDifferenceK,
    ::testing::Values(
        std::make_tuple(vector<int>{1,7,5,9,2,12,3}, 2, 4),
        std::make_tuple(vector<int>{1,2,3}, 2, 1),
        std::make_tuple(vector<int>{1,2,3}, 0, 3)
    )
);
