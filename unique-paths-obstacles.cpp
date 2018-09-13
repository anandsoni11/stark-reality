/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.
*/

#include <bits/stdc++.h>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        if (obstacleGrid[0][0]) return 0;
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<int> > res(r, vector<int>(c,0));
        res[0][0] = 1;
        for (int i=1; i<r; i++) {
            if (!obstacleGrid[i][0] && res[i-1][0]) res[i][0] = 1;
        }
        for (int j=1; j<c; j++) {
            if (!obstacleGrid[0][j] && res[0][j-1]) res[0][j] = 1;
        }
        
        for (int i=1; i<r; i++) {
            for (int j=1; j<c; j++) {
                if (!obstacleGrid[i][j]) res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[r-1][c-1];
    }
};
