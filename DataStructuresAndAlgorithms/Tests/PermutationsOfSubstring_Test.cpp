#include "../PermutationsOfSubstring.h"
#include "gtest/gtest.h"

using namespace std;

class ParameterizedPermutationsOfSubstring : public ::testing::TestWithParam<tuple<string, string, vector<int>>> {};
TEST_P(ParameterizedPermutationsOfSubstring, BruteForce)
{
    string smaller = std::get<0>(GetParam());
    string bigger = std::get<1>(GetParam());
    vector<int> expected = std::get<2>(GetParam());
    vector<int> actual = PermutationsOfSubstring().FindPermutationSubstringsSuboptimal(smaller, bigger);
    ASSERT_EQ(expected, actual);
}
INSTANTIATE_TEST_CASE_P(
    PermutationsOfSubstring,
    ParameterizedPermutationsOfSubstring,
    ::testing::Values(
        std::make_tuple("", "a", vector<int>{}),
        std::make_tuple("a", "", vector<int>{}),
        std::make_tuple("", "", vector<int>{}),
        std::make_tuple("a", "a", vector<int>{0}),
        std::make_tuple("a", "abc", vector<int>{0}),
        std::make_tuple("a", "abca", vector<int>{0, 3}),
        std::make_tuple("ab", "abca", vector<int>{0}),
        std::make_tuple("ab", "abcab", vector<int>{0, 3}),
        std::make_tuple("ab", "abcabcab", vector<int>{0, 3, 6}),
        std::make_tuple("d", "abcabcabdddddd", vector<int>{8, 9, 10, 11, 12, 13}),
        // other permutations of s
        std::make_tuple("ab", "aba", vector<int>{0, 1})
    )
);

class ParameterizedGetPermutationsOfString : public ::testing::TestWithParam<tuple<string, vector<string>>> {};
TEST_P(ParameterizedGetPermutationsOfString, BruteForce)
{
    string str = std::get<0>(GetParam());
    vector<string> expected = std::get<1>(GetParam());
    vector<string> actual = PermutationsOfSubstring().GetPermutationsOfString(str);
    ASSERT_EQ(expected, actual);
}
INSTANTIATE_TEST_CASE_P(
    GetPermutationsOfString,
    ParameterizedGetPermutationsOfString,
    ::testing::Values(
        std::make_tuple("", vector<string>{""}),
        std::make_tuple("a", vector<string>{"a"}),
        std::make_tuple("ab", vector<string>{"ab", "ba"}),
        std::make_tuple("abc", vector<string>{"abc", "acb", "bac", "bca", "cab", "cba"}),
        std::make_tuple("aab", vector<string>{"aab", "aba", "aab", "aba", "baa", "baa"})
    )
);
