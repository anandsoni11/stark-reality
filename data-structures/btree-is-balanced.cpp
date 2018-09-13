#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
typedef struct Node Node;

bool isbalanced(Node* root, int& height) {
    if (!root) return true;
    bool l, r;
    int lh=0, rh=0;
    l = isbalanced(root->left, lh);
    r = isbalanced(root->right, rh);

    height = 1 + max(lh, rh);

    if (lh-rh >= 2 || rh-lh >=2) return false;

    return l&&r;
}

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  Node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(isbalanced(root, height))
    printf("Tree is balanced\n");
  else
    printf("Tree is not balanced\n");    
 
  return 0;
}