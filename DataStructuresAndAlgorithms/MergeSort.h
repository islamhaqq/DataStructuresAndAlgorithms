#pragma once
#include <vector>

using namespace std;

/**
 * Algorithm:
 * 1. If the list has one element, return the list.
 * 2. Split the list into two halves.
 * 3. Recursive sort both halves using merge sort.
 * 4. Merge the sorted halves to produce the sorted list.
 */
class MergeSort
{
public:
    std::vector<int> Sort(const vector<int>& input) const
    {
        if (input.size() <= 1) return input;

        const pair<const int, const int> leftHalfRange = pair(0, (input.size() - 1) / 2);
        const pair<const int, const int> rightHalfRange = pair((input.size() - 1) / 2 + 1, input.size() - 1);

        vector<int> leftHalf;
        for (int i = leftHalfRange.first; i <= leftHalfRange.second; i++)
        {
            leftHalf.push_back(input[i]);
        }

        vector<int> rightHalf;
        for (int i = rightHalfRange.first; i <= rightHalfRange.second; i++)
        {
            rightHalf.push_back(input[i]);
        }

        return Merge(Sort(leftHalf), Sort(rightHalf));
    }

    // TODO: Refactor
    std::vector<int> Merge(const vector<int>& sortedLeftHalf, const vector<int>& sortedRightHalf) const
    {
        vector<int> merged;

        int leftHalfIndex = 0;
        int rightHalfIndex = 0;
        while (merged.size() != sortedLeftHalf.size() + sortedRightHalf.size() && leftHalfIndex < sortedLeftHalf.size() && rightHalfIndex < sortedRightHalf.size())
        {
            const int leftValue = sortedLeftHalf[leftHalfIndex];
            const int rightValue = sortedRightHalf[rightHalfIndex];
            if (leftValue < rightValue)
            {
                merged.push_back(leftValue);
                leftHalfIndex++;
            }
            else
            {
                merged.push_back(rightValue);
                rightHalfIndex++;
            }
        }

        while (leftHalfIndex < sortedLeftHalf.size())
        {
            merged.push_back(sortedLeftHalf[leftHalfIndex]);
            leftHalfIndex++;
        }
        while (rightHalfIndex < sortedRightHalf.size())
        {
            merged.push_back(sortedRightHalf[rightHalfIndex]);
            rightHalfIndex++;
        }

        return merged;
    }
};
