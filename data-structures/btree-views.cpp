#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* ltree;
    Node* rtree;
};
typedef struct Node Node;

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->ltree = NULL;
    node->rtree = NULL;
    return node;
}

void printInOrder(Node* root) {
    if (!root) return;
    else {
        printInOrder(root->ltree);
        cout << root->data << " ";
        printInOrder(root->rtree);
    }

}

void topView(Node* node) {
    if (!node) return;
    queue<pair<Node*,int> > q;
    unordered_map<int, int> Nmap;
    
    q.push(make_pair(node, 0));
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        Node* top = p.first;
        int hdist = p.second;
        q.pop();
        if (Nmap.find(hdist) == Nmap.end()) {
            Nmap[hdist] = top->data;
            cout << top->data << " ";
        }
        if (top->ltree) {
            q.push(make_pair(top->ltree,hdist-1));
        }
        if (top->rtree) {
            q.push(make_pair(top->rtree,hdist+1));
        }
    }
}

int main() {
    Node* root = createNode(1);
    root->ltree = createNode(2);
    root->rtree = createNode(3);
    root->ltree->ltree = createNode(4);
    root->ltree->rtree = createNode(5);
    root->rtree->ltree = createNode(6);
    root->rtree->rtree = createNode(7);	
    printInOrder(root);

    cout << endl; 

    topView(root);

    cout << endl;
}