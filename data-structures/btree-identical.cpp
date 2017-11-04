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

bool identicalTrees(Node* tree1, Node* tree2) {
    bool isDataSame = false;
    if (!tree1 && !tree2) return true;
    else if (!tree1 || !tree2) return false;
    else {
        isDataSame = (tree1->data == tree2->data) ? true : false;
        if (!isDataSame) return false;
        else {
            isDataSame = isDataSame && identicalTrees(tree1->ltree, tree2->ltree) && identicalTrees(tree1->rtree, tree2->rtree);
        }
    }
    return isDataSame;
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

    Node* root1 = createNode(1);
    root1->ltree = createNode(2);
    root1->rtree = createNode(3);
    root1->ltree->ltree = createNode(4);
    root1->ltree->rtree = createNode(5);
    root1->rtree->ltree = createNode(6);
    root1->rtree->rtree = createNode(8);	
    printInOrder(root1);

    cout << endl;

    bool identical = identicalTrees(root, root1);
    cout << identical << endl;
}