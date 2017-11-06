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

Node* lca(Node* root, int n1, int n2) {
    if(!root) return NULL;
    if(root->data < n1 && root->data < n2) {
        return lca(root->rtree, n1, n2);
    }
    if(root->data > n1 && root->data > n2) {
        return lca(root->ltree, n1, n2);
    }
    return root;
}

int main() {
    Node* root = createNode(20);
    root->ltree = createNode(8);
    root->rtree = createNode(22);
    root->ltree->ltree = createNode(4);
    root->ltree->rtree = createNode(12);
    root->ltree->rtree->ltree = createNode(10);
    root->ltree->rtree->rtree = createNode(14);	
    printInOrder(root);

    cout << endl;

    cout << lca(root, 10, 14)->data << endl;
    cout << lca(root, 14, 8)->data << endl;
    cout << lca(root, 10, 22)->data << endl;
    return 0;
}