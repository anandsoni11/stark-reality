/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <bits/stdc++.h>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int> > res(r, vector<int>(c,0));
        res[0][0] = grid[0][0];
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (i > 0 && j > 0) res[i][j] = min(res[i-1][j]+grid[i][j], res[i][j-1]+grid[i][j]);
                if (i > 0 && j<=0) res[i][j] = res[i-1][j]+grid[i][j];
                if (j > 0 && i<=0) res[i][j] = res[i][j-1]+grid[i][j];
            }
        }
        return res[r-1][c-1];
    }
};
