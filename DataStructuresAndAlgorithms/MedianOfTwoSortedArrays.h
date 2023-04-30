/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 */

#pragma once
#include <vector>

#include "MergeSort.h"


namespace Algorithms
{
    using namespace std;

    /** O(m + n) solution
     * 1. Merge the two arrays into one sorted array
     * 2. If there is an even number of elements, then get the average of the middle two elements
     * 3. If there is an odd number of elements, then get the middle element
     */
    inline double linearSolution(vector<int>& left, vector<int>& right)
    {
        const size_t combinedSize = left.size() + right.size();
        if (combinedSize == 0) return 0.0;

        if (combinedSize == 1)
        {
            if (left.size() == 1) return left[0];
            return right[0];
        }

        // 1. Merge the two arrays into one sorted array
        const vector<int> combined = MergeSort().Merge(left, right);

        const bool bIsEven = combined.size() % 2 == 0;
        if (bIsEven)
        {
            // 2. Median for even is the mean of the two middle elements
            return (combined[combined.size() / 2 - 1] + combined[combined.size() / 2]) / 2.0;
        }
        // 3. Median for odd is the middle element
        return int(combined[combined.size() / 2]);
    }

    /** O(log (m + n)) solution
     * 1. Make sure the left array is smaller
     * 2. Make the arrays the same size, without touching the array (using the indexes)
     * 3. If there is an even number of elements, then get the average of the middle two elements
     * 4. If there is an odd number of elements, then get the middle element
     */
    inline double logarithmicSolution(vector<int>& left, vector<int>& right)
    {
        // The gist of the problem is, if we can get rid of the merging operation of the linear solution, which requires a loop,
        // and just deal wih indexes. It could have been possible to do this in constant time if there was just one array,
        // because we know the median is the middle index if odd, and the mean of the middle two if even.
        // Well, we know that if both arrays are the same size, that means it is even, and that means the median
        // is the average of max(left) and min(right). And if it is odd, given that the first array is smaller,
        // then the median will always be max(left).
        // Input: nums1 = [1,5], nums2 = [2,3,4,6,7,8,9]
        // Output: 5.00000

        // 1. Make sure the left array is smaller
        if (right.size() < left.size()) logarithmicSolution(right, left);

        const size_t combinedSize = left.size() + right.size();
        const bool bIsEven = combinedSize % 2 == 0;
        // 2. Make the arrays the same size, without touching the array (using the indexes)

        // TODO: finish logarithmic solution.
        
    
        return linearSolution(left, right);
    }

    inline double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        return logarithmicSolution(nums1, nums2);
    }
}
