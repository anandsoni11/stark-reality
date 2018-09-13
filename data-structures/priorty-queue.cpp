#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<int> q;
    int parent(int i) {
        if (i==0) return i;
        return (i-1)/2;
    }

    int leftchild(int i) {
        return 2*i + 1;
    }

    int rightchild(int i) {
        return 2*i + 2;
    }

    void percolateup(int n) {
        int pn = parent(n);
        if (n < q.size() && pn < q.size() && q[pn] < q[n]) {
            swap(n, pn);
            percolateup(pn);
        }
    }

    void percolatedown(int n) {
        int left = leftchild(n);
        int right = rightchild(n);
        int largest = n;
        if (left < q.size() && q[left] > q[n]) {
            largest = left;
        }
        if (right < q.size() && q[right] > q[n]) {
            largest = right;
        }
        if (largest != n) {
            swap(n, largest);
            percolatedown(largest);
        }
    }

    void swap(int i, int j) {
        int temp = q[i];
        q[i] = q[j];
        q[j] = temp;
    }
public:
    void push(int key) {
        q.push_back(key);
        percolateup(q.size() - 1);
    }

    int pop() {
        int size = q.size();
        if (size != 0) {
            q[0] = q[size-1];
            q.pop_back();
            percolatedown(0);
        }
    }

    int top() {
        if (q.size() != 0) {
            return q[0];
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.push(3);
    pq.push(2);
    pq.push(15);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    pq.push(5);
    pq.push(4);
    pq.push(45);

    cout << pq.top() << endl;
    pq.pop();

    pq.push(67);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    return 0;
}