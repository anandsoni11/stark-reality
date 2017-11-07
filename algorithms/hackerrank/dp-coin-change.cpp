#include <bits/stdc++.h>

using namespace std;

long countWays(long n, vector<long> c, int m, vector<vector<long> >& ways);

long getWays(long n, vector < long > c){
    // Complete this function
    int m = c.size();
    vector<vector<long> > ways(n+1, vector<long>(m,-1));
    return countWays(n,c,m-1,ways);
}

long countWays(long n, vector<long> c, int m, vector<vector<long> >& ways) {
    // If value already exists in stored ones, return it.
    if (ways[n][m] != -1) return ways[n][m];
    if (n == 0) {
        ways[n][m] = 0;
        return 0;
    }
    // If there is only one type of coin, there is 0 OR 1 solution.
    if (m == 0) {
        long nWays = (n%c[m] == 0 && n >= c[m]) ? 1 : 0;
        ways[n][m] = nWays;
        return nWays;
    }

    if (n >= c[m]) {
        long nWays = 0;
        // The recursion - number of solutions with m coins is :
        // number of solutions with m-1 coins + (now mandatorily include the mth coin)
        // number of solutions to (n - value of mth coin) with m coins
        if (n > c[m]) nWays = countWays(n, c, m-1, ways) + countWays(n-c[m], c, m, ways);
        else nWays = countWays(n, c, m-1, ways) + 1;
        ways[n][m] = nWays;
        return nWays;
    }
    else {
        long nWays = countWays(n, c, m-1, ways);
        ways[n][m] = nWays;
        return nWays;
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways;
    return 0;
}
