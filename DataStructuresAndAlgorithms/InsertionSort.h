#pragma once
#include "vector"

using namespace std;

class InsertionSort
{
public:
    void Sort(vector<int>& array)
    {
        SortWithConstantSpaceComplexity(array);
    }

    // TODO: O(n^2) runtime complexity, O(1) space complexity
    void SortOptimal(vector<int>& array)
    {
        
    }

    // O(n^3) runtime complexity, O(1) space complexity
    void SortWithConstantSpaceComplexity(vector<int>& array)
    {
        if (array.size() < 2) return;

        int sortedLength = 1;
        for (int i = 1; i < array.size() ; i++)
        {
            const int element = array[i];

            const size_t size = sortedLength; 
            for (int j = 0; j < size; j++)
            {
                const int current = array[j];
                if (element < current)
                {
                    array.erase(array.begin() + i);
                    array.emplace(array.begin() + j, element);
                    sortedLength++;
                    break;
                }
                if (j == size - 1)
                {
                    array.erase(array.begin() + i);
                    array.emplace(array.begin() + j + 1, element);
                    sortedLength++;
                }
            }
        }
    }
    
    // O(n^2) runtime complexity, O(n) space complexity
    vector<int> SortWithLinearSpaceComplexity(const vector<int>& array)
    {
        if (array.size() < 2) return array;
        
        vector<int> sortedArray = { array[0] };

        // O(n)
        for (int i = 1; i < array.size(); i++)
        {
            const int element = array[i];
            
            // O(n)
            const size_t sortedArraySize = sortedArray.size();
            for (int j = 0; j < sortedArraySize; j++)
            {
                if (element <= sortedArray[j])
                {
                    sortedArray.emplace(sortedArray.begin() + j, element);
                    break;
                }
                if (j == sortedArraySize - 1)
                {
                    sortedArray.push_back(element);
                }
            }
        }

        return sortedArray;
    }
};