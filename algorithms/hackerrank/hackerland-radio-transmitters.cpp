#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int getMinTransmitters(vector<int> a, int n, int k) {
    sort(a.begin(), a.end());
    int count = 0;
    int i =0;
    while (i < n) {
        int pos = a[i] + k;
        while (i < n && a[i] <= pos) i++;
        i--;
        count++;
        pos = a[i] + k;
        while (i < n && a[i] <= pos) i++;
    }
    return count;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    int res = getMinTransmitters(x, n, k);
    cout << res;
    return 0;
}

