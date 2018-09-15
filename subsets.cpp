/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        subsets_helper(result, temp, nums, 0);
        return result;
    }
    
private:
    void subsets_helper(vector<vector<int> >& res, vector<int>& temp, vector<int> nums, int start) {
        res.push_back(temp);
        for (int i=start; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            subsets_helper(res, temp, nums, i+1);
            temp.pop_back();
        }
    }
};
