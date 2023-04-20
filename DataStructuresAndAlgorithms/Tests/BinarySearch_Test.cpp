// Copyright Syed Aman. All Rights Reserved.

#include <gtest/gtest.h>

#include "../BinarySearch.h"

using namespace std;

TEST(BinarySearch, ShouldSearchCorrectIndex)
{
    const vector SortedArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    constexpr int TargetValue = 5;
    constexpr int ExpectedIndex = 4;

    const size_t ActualIndex = Algorithms::BinarySearch(SortedArray.data(), SortedArray.size(), TargetValue);
    EXPECT_EQ(ExpectedIndex, ActualIndex);
}

TEST(BinarySearch, ShouldSearchCorrectIndexWithProjection)
{
    const vector SortedArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    constexpr int TargetValue = 20;
    constexpr int ExpectedIndex = 9; // Since value 10 at index 9 will be multiplied by 2 and will be 20

    const size_t ActualIndex2 = Algorithms::BinarySearch(SortedArray.data(), SortedArray.size(), TargetValue, [](const int& Value) { return Value * 2; }, less<int>());
    EXPECT_EQ(ActualIndex2, ExpectedIndex);
}

TEST(BinarySearch, ShouldSearchOtherTypes)
{
    const vector SortedArray = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
    constexpr float TargetValue = 5.0f;
    constexpr int ExpectedIndex = 4;

    const size_t ActualIndex = Algorithms::BinarySearch(SortedArray.data(), SortedArray.size(), TargetValue);
    EXPECT_EQ(ExpectedIndex, ActualIndex);

    const vector SortedCharArray = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    constexpr char TargetChar = 'e';
    constexpr int ExpectedCharIndex = 4;

    const size_t ActualCharIndex = Algorithms::BinarySearch(SortedCharArray.data(), SortedCharArray.size(), TargetChar);
    EXPECT_EQ(ExpectedCharIndex, ActualCharIndex);
}