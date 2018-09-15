/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 1) {
            vector<vector<int> > r(n, vector<int>());
            for (int i=0; i<n; i++) {
                r[i].push_back(i+1);
            }
            return r;
        }
        
        if (k >= n) {
            vector<vector<int> > r(1, vector<int>());
            for (int i=0; i<n; i++) {
                r[0].push_back(i+1);
            }
            return r;
        }
        
        vector<vector<int> > res;
        vector<vector<int> > r;
        for (int i=n; i>=k; i--) {
            r = combine(i-1, k-1);
            for (int j=0; j<r.size(); j++) {
                r[j].push_back(i);
                res.push_back(r[j]);
            }
        }
        return res;
    }
};
