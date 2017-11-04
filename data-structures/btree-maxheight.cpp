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

int maxHeight(Node* node) {
    if (!node) return 0;
    else {
        return 1 + max(maxHeight(node->ltree), maxHeight(node->rtree));
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

    int mHeight = maxHeight(root);
    cout << mHeight << endl;
}