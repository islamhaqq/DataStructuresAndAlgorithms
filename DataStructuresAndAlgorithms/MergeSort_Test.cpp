#include <gtest/gtest.h>

#include "MergeSort.h"

using namespace std;

class ParameterizedMergeSort : public ::testing::TestWithParam<tuple<vector<int>, vector<int>>> {};
TEST_P(ParameterizedMergeSort, Sort)
{
    vector<int> input = std::get<0>(GetParam());
    const vector<int> expected = std::get<1>(GetParam());
    const vector<int> actual = MergeSort().Sort(input);
    ASSERT_EQ(expected, actual);
}
INSTANTIATE_TEST_CASE_P(
    MergeSort,
    ParameterizedMergeSort,
    ::testing::Values(
        std::make_tuple(vector<int>{}, vector<int>{}),
        std::make_tuple(vector<int>{1}, vector<int>{1}),
        std::make_tuple(vector<int>{1, 2}, vector<int>{1, 2}),
        std::make_tuple(vector<int>{2, 1}, vector<int>{1, 2}),
        std::make_tuple(vector<int>{1, 2, 3}, vector<int>{1, 2, 3}),
        std::make_tuple(vector<int>{3,100,1,3,0,-5,7,2,8}, vector<int>{-5,0,1,2,3,3,7,8,100})
    )
);

class ParameterizedMerge : public ::testing::TestWithParam<tuple<vector<int>, vector<int>, vector<int>>> {};
TEST_P(ParameterizedMerge, Sort)
{
    vector<int> left = std::get<0>(GetParam());
    vector<int> right = std::get<1>(GetParam());
    const vector<int> expected = std::get<2>(GetParam());
    const vector<int> actual = MergeSort().Merge(left, right);
    ASSERT_EQ(expected, actual);
}
INSTANTIATE_TEST_CASE_P(
    Merge,
    ParameterizedMerge,
    ::testing::Values(
        std::make_tuple(vector<int>{}, vector<int>{}, vector<int>{}),
        std::make_tuple(vector<int>{1}, vector<int>{1}, vector<int>{1,1}),
        std::make_tuple(vector<int>{2}, vector<int>{1}, vector<int>{1,2}),
        std::make_tuple(vector<int>{2}, vector<int>{1,3}, vector<int>{1,2,3}),
        std::make_tuple(vector<int>{0,2,3,100}, vector<int>{-5,1,3,7,8}, vector<int>{-5,0,1,2,3,3,7,8,100})
    )
);