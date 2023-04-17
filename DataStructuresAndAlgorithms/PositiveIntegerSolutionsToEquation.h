/**
 * Print all positive integer solutions to the equation a^3 + b^3 = c^3 + d^3 where a, b, c, and d are integers between 1 and 1000.
 */

#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class PositiveIntegerSolutionsToEquation
{
public:
    // O(n^2) - 1 million iterations given n = 1000
    void Memo(int n = 1000)
    {
        unordered_map<int, vector<vector<int>>> memo;
        for (int c = 1; c <= n; c++)
        {
            for (int d = 1; d <= n; d++)
            {
                int sum = c * c * c + d * d * d;
                memo[sum].push_back({ c, d });
            }
        }
        
        for (auto& [sum, pairs] : memo)
        {
            for (int i = 0; i < pairs.size(); i++)
            {
                for (int j = 0; j < pairs.size(); j++)
                {
                    cout << pairs[i][0] << "^3 + " << pairs[i][1] << "^3 = " << pairs[j][0] << "^3 + " << pairs[j][1] << "^3" << endl;
                }
            }
        }
    }
    
    // O(n^3) - 1 billion iterations given n = 1000
    void SimpleMath(int n = 1000)
    {
        // Compute for d where d = (a^3 + b^3 - c^3)^(1/3)
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                for (int c = 1; c <= n; c++)
                {
                    int d = pow(a * a * a + b * b * b - c * c * c, 1.0 / 3.0);
                    if (d * d * d == a * a * a + b * b * b - c * c * c)
                    {
                        cout << a << "^3 + " << b << "^3 = " << c << "^3 + " << d << "^3" << endl;
                    }
                }
            }
        }
    }
    
    // O(n^4) - 1 trillion iterations given n = 1000
    void BruteForce(int n = 1000)
    {
        vector<vector<int>> solutions;
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                for (int c = 1; c <= n; c++)
                {
                    for (int d = 1; d <= n; d++)
                    {
                        if (a * a * a + b * b * b == c * c * c + d * d * d)
                        {
                            vector<int> solution = {a, b, c, d};
                            cout << a << "^3 + " << b << "^3 = " << c << "^3 + " << d << "^3" << endl;
                        }
                    }
                }
            }
        }
    }
};

