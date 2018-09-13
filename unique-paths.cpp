/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include <bits/stdc++.h>

class Solution {
public:
    int uniquePaths1(int m, int n) {
        vector<vector<int> > res(m, vector<int>(n,1));
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
    
    /*
    This is a combinatorial problem and can be solved without DP. For mxn grid, robot has to move exactly m-1 steps down and n-1 steps right and these can be done in any order.

    For the eg., given in question, 3x7 matrix, robot needs to take 2+6 = 8 steps with 2 down and 6 right in any order. That is nothing but a permutation problem. Denote down as 'D' and right as 'R', following is one of the path :-

    D R R R D R R R

    We have to tell the total number of permutations of the above given word. So, decrease both m & n by 1 and apply following formula:-

    Total permutations = (m+n)! / (m! * n!)
    */ 
    int uniquePaths2(int m, int n) {
        if (m==1 || n==1) return 1;
        m--;
        n--;
        long res=1;
        int j=1;
        for (int i=m+1; i<=m+n; i++; j++) {
            res = res*i;
            res = res/j;
        }
        return (int)res;
    }
};
