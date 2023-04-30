#pragma once
#include <gtest/gtest.h>
#include <vector>

#include "InsertionSort.h"

using namespace std;

class ParameterizedInsertionSort : public ::testing::TestWithParam<tuple<vector<int>, vector<int>>> {};
TEST_P(ParameterizedInsertionSort, Sort)
{
    vector<int> actual = std::get<0>(GetParam());
    const vector<int> expected = std::get<1>(GetParam());

    InsertionSort().Sort(actual);

    EXPECT_EQ(actual, expected);
}
INSTANTIATE_TEST_CASE_P(
    InsertionSort,
    ParameterizedInsertionSort,
    ::testing::Values(
        std::make_tuple(vector<int>{}, vector<int>{}),
        std::make_tuple(vector<int>{1}, vector<int>{1}),
        std::make_tuple(vector<int>{1, 2}, vector<int>{1, 2}),
        std::make_tuple(vector<int>{2, 1}, vector<int>{1, 2}),
        std::make_tuple(vector<int>{1, 2, 3}, vector<int>{1, 2, 3}),
        std::make_tuple(vector<int>{3,100,1,3,0,-5,7,2,8}, vector<int>{-5,0,1,2,3,3,7,8,100})
    )
);