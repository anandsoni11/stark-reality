/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(res, temp, candidates, target, 0);
        return res;
    }
    
private:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int> candidates, int target, int start) {
        if (target < 0) return;
        if (target == 0) res.push_back(temp);
        else {
            for (int i=start; i<candidates.size(); i++) {
                if (i>start && candidates[i] == candidates[i-1]) continue;
                temp.push_back(candidates[i]);
                backtrack(res, temp, candidates, target-candidates[i], i+1);
                temp.pop_back();
            }
        }
    }
};
