#pragma once
#include <vector>

#include "MergeSort.h"


namespace Algorithms
{
    using namespace std;

    // O(m + n)
    inline double linearSolution(vector<int>& nums1, vector<int>& nums2)
    {
        const size_t combinedSize = nums1.size() + nums2.size();
        if (combinedSize == 0) return 0.0;
        if (combinedSize == 1) return nums1.size() > nums2.size() ? nums1[0] : nums2[0];

        vector<int> combined = MergeSort().Merge(nums1, nums2);
        bool bIsEven = combined.size() % 2 == 0;
        if (bIsEven)
        {
            // Median for even is the mean of the two middle elements
            return (combined[combined.size() / 2 - 1] + combined[combined.size() / 2]) / 2.0;
        }
        // Median for odd is the middle element
        return int(combined[combined.size() / 2]);
    }

    // O(log (m + n))
    inline double logarithmicSolution(vector<int>& nums1, vector<int>& nums2)
    {
        // The gist of the problem is, if we can get rid of the merging operation of the linear solution, which requires a loop,
        // and just deal wih indexes. It could have been possible to do this in constant time if there was just one array,
        // because we know the median is the middle index if odd, and the mean of the middle two if even.
        // Well, we know that if both arrays are the same size, that means it is even, and that means the median
        // is the average of max(nums1) and min(nums2). And if it is odd, given that the first array is smaller,
        // then the median will always be max(nums1).

        // 1. Make sure the left array is smaller
        if (nums2.size() < nums1.size()) logarithmicSolution(nums2, nums1);

        const size_t combinedSize = nums1.size() + nums2.size();
        const bool bIsEven = combinedSize % 2 == 0;
        // 2. Make the arrays the same size, without touching the array (using the indexes)

        // TODO: finish logarithmic solution.
        return linearSolution(nums1, nums2);
    }

    inline double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        return logarithmicSolution(nums1, nums2);
    }
}
