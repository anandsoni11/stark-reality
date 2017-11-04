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

Node* mirror(Node* node) {
    if (!node) return NULL;
    else {
        Node* mirrorNode = new Node();
        mirrorNode->data = node->data;
        mirrorNode->ltree = mirror(node->rtree);
        mirrorNode->rtree = mirror(node->ltree);
        return mirrorNode;
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

    Node* mirrorRoot = mirror(root);
    printInOrder(mirrorRoot);

    cout << endl;
}