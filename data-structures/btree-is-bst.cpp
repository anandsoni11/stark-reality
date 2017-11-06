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

bool isBstHelper(Node* root, int min, int max);

bool isBst(Node* root) {
    return isBstHelper(root, INT_MIN, INT_MAX);
}

bool isBstHelper(Node* root, int min, int max) {
    if (!root) return true;
    if (root->data < min || root->data > max) return false;
    return (isBstHelper(root->ltree, min, root->data - 1) && isBstHelper(root->rtree, root->data + 1, max));
}

int main() {
    Node *root = createNode(4);
    root->ltree = createNode(2);
    root->rtree = createNode(5);
    root->ltree->ltree = createNode(1);
    root->ltree->rtree = createNode(3); 
    cout << isBst(root) << endl;
    return 0;
}