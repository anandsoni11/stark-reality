/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
#include <bits/stdc++.h>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        int maxReach = 0;
        for (int i=0; i<l; i++) {
            if (i + nums[i] >= maxReach && maxReach >= i) {
                maxReach = i + nums[i];
            }
            if (maxReach >= l-1) return true;
        }
        return false;
    }
};
