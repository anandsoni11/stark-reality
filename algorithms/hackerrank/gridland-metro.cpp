#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > grid(n, vector<int>(m));
    int train_track_count = 0;
    while (k-- != 0) {
        int r, c1, c2;
        cin >> r >> c1 >> c2;
        for (int j=c1; j<=c2; j++) {
            if (grid[r-1][j-1] != 1) {
                grid[r-1][j-1] = 1;
                train_track_count++;   
            }
        }
    }
    int lampposts = n*m - train_track_count;
    cout << lampposts;
    return 0;
}
