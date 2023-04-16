/**
 * Print all positive integer solutions to the equation a^3 + b^3 = c^3 + d^3 where a, b, c, and d are integers between 1 and 1000.
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class PositiveIntegerSolutionsToEquation
{
public:
    // O(n^3) - 1 billion iterations given n = 1000
    void SimpleMath()
    {
        // Compute for d where d = (a^3 + b^3 - c^3)^(1/3)
        for (int a = 1; a <= 1000; a++)
        {
            for (int b = 1; b <= 1000; b++)
            {
                for (int c = 1; c <= 1000; c++)
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
    void BruteForce()
    {
        vector<vector<int>> solutions;
        for (int a = 1; a <= 1000; a++)
        {
            for (int b = 1; b <= 1000; b++)
            {
                for (int c = 1; c <= 1000; c++)
                {
                    for (int d = 1; d <= 1000; d++)
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

