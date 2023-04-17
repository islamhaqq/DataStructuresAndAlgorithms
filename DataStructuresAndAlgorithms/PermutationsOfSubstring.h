/**
  * Example: Given a smaller strings and a bigger string b, design an algorithm to find all permutations of the
  * shorter string within the longer one. Print the location of each permutation. 
  */

#include <string>
#include <vector>
using namespace std;

class PermutationsOfSubstring
{
public:
    // O(s! * b)
    vector<int> FindPermutationSubstrings(const string& smaller, const string& bigger)
    {
        vector<int> locations;

        // O(s!)
        vector<string> permutations = GetPermutationsOfString(smaller);

        // O(s! * b)
        for (string permutation : permutations)
        {
            for (int i = 0; i < bigger.size(); i++)
            {
                if (permutation[0] == bigger[i])
                {
                    bool isSubstring = true;
                    for (int j = 0; j < permutation.size(); j++)
                    {
                        if (permutation[j] != bigger[i + j])
                        {
                            isSubstring = false;
                            break;
                        }
                    }
                    if (isSubstring)
                        locations.push_back(i);
                }
            }
        }

        
        return locations;
    }

    // O(n!)
    vector<string> GetPermutationsOfString(string Str)
    {
        if (Str.size() == 1 || Str.empty())
            return vector<string>{Str};
        
        // 1. Each of the first characters
        vector<string> permutations;
        for (int i = 0; i < Str.size(); i++)
        {
            char firstCharacter = Str[i];

            // 2. concatenated by the permutations of the rest
            string theRest;
            for (int j = 0; j < Str.size(); j++)
            {
                if (j == i) continue;
                theRest += Str[j];
            }
            
            vector<string> permutationsOfTheRest = GetPermutationsOfString(theRest);
            for (string permutation : permutationsOfTheRest)
            {
                string permutationWithFirstCharacter;
                permutationWithFirstCharacter += firstCharacter;
                permutationWithFirstCharacter += permutation;
                permutations.push_back(permutationWithFirstCharacter);
            }
        }
        return permutations;
    }
};
