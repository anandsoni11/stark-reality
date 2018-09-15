/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <bits/stdc++.h>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur=0, left=0, right = nums.size()-1;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[left], nums[cur]);
                left++;
                cur++;
            }
            else if (nums[cur] == 2) {
                swap(nums[right], nums[cur]);
                right--;
            }
            else cur++;
        }
    }
};


