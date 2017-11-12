#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, int l, int m, int r);
void mergesort(vector<int>& v, int l, int r) {
    if (r > l) {
        int m = (l+r)/2;
        mergesort(v, l, m);
        mergesort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void merge(vector<int>& v, int l, int m, int r) {
    int i = l;
    int j = m+1;
    if (v[m] > v[m+1]) {
        vector<int> temp;
        while (i <= m && j <= r) {
            if (v[i] > v[j]) {
                temp.push_back(v[j]);
                j++;
            }
            else {
                temp.push_back(v[i]);
                i++;
            }
        }
        while (j <= r) {
            temp.push_back(v[j]);
            j++;
        }

        while (i <= m) {
            temp.push_back(v[i]);
            i++;    
        }
        for (int k=0; k<temp.size(); k++) {
            v[k] = temp[k];
        }
    }
}

void printVector(vector<int> v)
{
    int i;
    for (i=0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
}
 
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();
 
    printVector(arr);
 
    mergesort(arr, 0, arr_size - 1);
 
    printVector(arr);
    return 0;
}