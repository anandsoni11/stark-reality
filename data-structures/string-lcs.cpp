#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
    vector<vector<int> > L(m+1, vector<int>(n+1, 0));
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                L[i][j] = 1 + L[i-1][j-1];
            }
            else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[m][n];
}
int main()
{
  string X = "ANANDSONI";
  string Y = "AXYNLAZZNWD";
  
  int m = 9;
  int n = 11;
  
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
 
  return 0;
}