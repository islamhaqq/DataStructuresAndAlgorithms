#pragma once
#include <vector>


namespace Algorithms
{
    using namespace std;

    // O(m + n)
    inline double linearSolution(vector<int>& nums1, std::vector<int>& nums2)
    {
        double sum = 0;
        int size = 0;
        for (const int num : nums1)
        {
            sum += num;
            size++;
        }
        for (const int num : nums2)
        {
            sum += num;
            size++;
        }

        if (size == 0) return 0.0;

        return sum / size;
    }

    // O(log (m + n))
    inline double logarithmicSolution(vector<int>& nums1, std::vector<int>& nums2)
    {
        double sum = 0;
        vector<int> combined;
        for (int num : nums1)
        {
            combined.push_back(num);
            sum += num;
        }
        for (int num : nums2)
        {
            combined.push_back(num);
            sum += num;
        }

        if (combined.empty()) return 0.0;
        if (combined.size() == 1) return combined[0];

        return sum / combined.size();
    }

    inline double findMedianSortedArrays(vector<int>& nums1, std::vector<int>& nums2)
    {
        return linearSolution(nums1, nums2);
    }
}
