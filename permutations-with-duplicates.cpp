/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(res, temp, nums, used);
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int> nums, vector<bool>& used) {
        if (temp.size() == nums.size()) res.push_back(temp);
        else {
            for (int i=0; i<nums.size(); i++) {
                if (used[i] || i > 0 && nums[i-1] == nums[i] && !used[i-1]) continue;
                used[i] = true;
                temp.push_back(nums[i]);
                backtrack(res, temp, nums, used);
                used[i] = false;
                temp.pop_back();
            }
        }
    }
};
