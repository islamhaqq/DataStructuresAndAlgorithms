// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

#include <vector>

using namespace std;

/**
 * The first solution is the least optimal solution which involves a complete brute force approach where we
 * use recursion to break this large problem into a smaller problem. The smallest problem is if we have no moves, in that
 * case it is 0.
 *
 * And if we have 1 move, we choose the coin on the next pile if available, keeping track of the total so far and max, and then
 * starting over and choosing the coin on the current pile if available, keeping track of the total and max, and then returning the
 * max so far.
 *
 * Anything larger than 1 is the same thing as 1 move
 */
class Solution1 {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) { 
        int maxTotal = 0;
        BruteForce(piles, k, 0, 0, 0, maxTotal);
        return maxTotal;
    }
    
private:
    void BruteForce(vector<vector<int>>& piles, int k, int pile, int coinsTaken, int totalValue, int& maxTotal)
    {
        if (coinsTaken == k)
        {
            maxTotal = max(maxTotal, totalValue);
            return;
        }
        if (HasNoPiles(piles, pile)) return;
        
        Option1SkipCurrentPile(piles, k, pile, coinsTaken, totalValue, maxTotal);
        Option2StartWithCurrentPile(piles, k, pile, coinsTaken, totalValue, maxTotal);
    }

    void Option1SkipCurrentPile(vector<vector<int>>& piles, int k, int pile, int coinsTaken, int totalValue, int& maxTotal)
    {
        BruteForce(piles, k, pile + 1, coinsTaken, totalValue, maxTotal);
    }

    void Option2StartWithCurrentPile(vector<vector<int>>& piles, int k, int pile, int coinsTaken, int totalValue, int& maxTotal)
    {
        if (!piles[pile].empty())
        {
            int coin = piles[pile].front();
            piles[pile].erase(piles[pile].begin());
            BruteForce(piles, k, pile, coinsTaken + 1, totalValue + coin, maxTotal);
            piles[pile].insert(piles[pile].begin(), coin);
        }
    }

    bool HasNoPiles(vector<vector<int>>& piles, int pile)
    {
        return pile >= piles.size();
    }
};

/**
 * The thing about recursive brute force solutions like this (fibonacci, factorial, etc), with repeat subproblems,
 * is that they can be optimized by using memoization (dynamic programming).
 */
class Solution2
{
public:
    int bruteForceMemo(vector<vector<int>>& piles, int k, int pile, int coinsTaken, vector<vector<int>>& memo)
    {
        if (coinsTaken == k)
        {
            return 0;
        }

        if (pile >= piles.size()) return 0;

        // Return the cached value if we have it
        if (memo[pile][coinsTaken] != -1) return memo[pile][coinsTaken];

        // Option 1: skip current pile and go to the next
        int skipPile = bruteForceMemo(piles, k, pile + 1, coinsTaken, memo);

        // Option 2: start with the current pile
        int currentPile = 0;
        if (!piles[pile].empty())
        {
            int coin = piles[pile].front();
            piles[pile].erase(piles[pile].begin());
            currentPile = coin + bruteForceMemo(piles, k, pile, coinsTaken + 1, memo);
            piles[pile].insert(piles[pile].begin(), coin);
        }

        int maxTotal = max(skipPile, currentPile);

        // Cache the value
        memo[pile][coinsTaken] = maxTotal;

        return maxTotal;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) { 
        vector<vector<int>> memo(piles.size(), vector<int>(k + 1, -1));
        return bruteForceMemo(piles, k, 0, 0, memo);
    }
};