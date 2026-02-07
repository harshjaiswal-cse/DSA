#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> combination;
        
        // Sorting allows us to stop exploring a branch early (pruning)
        // if the current number already exceeds the remaining target.
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, combination, results);
        return results;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& combination, vector<vector<int>>& results) {
        
        // Base case: If target is hit, we found a valid path
        if (target == 0) {
            results.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Pruning: if candidates[i] > target, no need to check 
            // this or any larger numbers in the sorted array.
            if (candidates[i] > target) break;

            // 1. Action: add the candidate to our current path
            combination.push_back(candidates[i]);

            // 2. Explore: we pass 'i' as the start index because 
            // we can reuse the same element multiple times.
            backtrack(candidates, target - candidates[i], i, combination, results);

            // 3. Backtrack: remove the element to try other options
            combination.pop_back();
        }
    }
};