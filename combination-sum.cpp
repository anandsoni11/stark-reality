/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
*/

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, temp, candidates, target, 0);
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int> candidates, int target, int start) {
        if (target < 0) return;
        if (target == 0) res.push_back(temp);
        else {
            for (int i=start; i<candidates.size(); i++) {
                temp.push_back(candidates[i]);
                backtrack(res, temp, candidates, target-candidates[i], i);
                temp.pop_back();
            }
        }
    }
};
