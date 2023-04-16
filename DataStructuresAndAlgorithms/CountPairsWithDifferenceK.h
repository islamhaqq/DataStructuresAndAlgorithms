/**
  * Given an array of distinct integer values, count the number of pairs of integers that 
  * have difference k. For example, given the array { 1, 7, 5, 9, 2, 12, 3} and the difference 
  * k = 2,there are four pairs with difference2: (1, 3), (3, 5), (5, 7), (7, 9).
  * From Cracking the Coding Interview
  */

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    // O(n)
    int CountPairs(const vector<int>& Nums, int K)
    {
        int Pairs = 0;
        unordered_map<int, int> Map;
        for (int Num : Nums)
        {
            int targetDifference = Num + K;
            int targetDifference2 = Num - K;
            if (Map.contains(targetDifference))
            {
                Pairs++;
            }
            else
            {
                Map[Num] = targetDifference;
            }
            if (Map.contains(targetDifference2))
            {
                Pairs++;
            }
            else
            {
                Map[Num] = targetDifference2;
            }
        }
        return Pairs;
    }

    // O(nlogn)
    int WithSort(const vector<int>& Nums, int K)
    {
        int pairs = 0;

        vector<int> sortedNums = Nums;
        ranges::sort(sortedNums);

        for (int i = 0; i < sortedNums.size(); i++)
        {
            int num = sortedNums[i];
            int target = num + K;
            int result = binary_search(sortedNums.begin(), sortedNums.end(), target);
            if (result)
            {
                ++pairs;
            }
        }
        return pairs;
    }

    // O(n^2)
    int BruteForce(const vector<int>& Nums, int K)
    {
        int pairs = 0;
        for (int num : Nums)
        {
            for (int num2 : Nums)
            {
                if (num - num2 == K)
                {
                    ++pairs;
                }
            }
        }
        return pairs;
    }
};
