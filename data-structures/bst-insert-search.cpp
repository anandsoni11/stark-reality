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

Node* insert(Node* root, int key) {
    if(!root) return createNode(key);
    if (key < root->data) {
        root->ltree = insert(root->ltree, key);
    }
    if (key > root->data) {
        root->rtree = insert(root->rtree, key);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) {
        return search(root->ltree, key);
    }
    else {
        return search(root->rtree, key);
    }
}

Node* minKeyNode(Node* root) {
    if (!root) return root;
    Node* current = root;
    while (current->ltree) {
        current = current->ltree;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if(!root) return root;
    if (key < root->data) {
        root->ltree = deleteNode(root->ltree, key);
    }
    else if (key > root->data) {
        root->rtree = deleteNode(root->rtree, key);
    }
    else {
        if (!root->ltree) {
            Node* temp = root->rtree;
            free(root);
            return temp;
        }
        else if(!root->rtree) {
            Node* temp = root->ltree;
            free(root);
            return temp;
        }
        Node* temp = minKeyNode(root->rtree);
        root->data = temp->data;
        root->rtree = deleteNode(root->rtree, temp->data);
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

    root = insert(root, 26);
    printInOrder(root);
    cout << endl;

    root = deleteNode(root, 20);
    printInOrder(root);
    cout << endl;

    return 0;
}