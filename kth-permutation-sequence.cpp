/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
*/

#include <bits/stdc++.h>

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n+1,1);
        string res = "";
        vector<int> fact(n,1);
        for (int i=0; i<=n; i++) nums[i]=i+1;
        for (int i=1; i<n; i++) fact[i] = i*fact[i-1];
        k--;
        for (int i=n; i>0; i--) {
            int index = k/fact[i-1];
            k = k%fact[i-1];
            res += to_string(nums[index]);
            nums.erase(nums.begin()+index);
        }
        return res;
    }
};

/*
Solution :
The logic is as follows: for n numbers the permutations can be divided to (n-1)! groups, for n-1 numbers can be divided to (n-2)! groups, and so on. Thus k/(n-1)! indicates the index of current number, and k%(n-1)! denotes remaining index for the remaining n-1 numbers.
We keep doing this until n reaches 0, then we get n numbers permutations that is kth.
*/
