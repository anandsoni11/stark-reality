/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        backtrack(res, temp, s, 0);
        return res;
    }

private:
    void backtrack(vector<vector<string>>& res, vector<string>& temp, string s, int start) {
        if (start == s.size()) res.push_back(temp);
        else {
            for (int i=start; i<s.size(); i++) {
                if (isPalindrome(s, start, i)) {
                    temp.push_back(s.substr(start, (i-start)+1));
                    backtrack(res, temp, s, i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
