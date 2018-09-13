#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node Node;

void splitlist(Node* head, Node** front, Node** back);
Node* mergelists(Node* a, Node* b);

void mergesort(Node** head) {
    Node* headp = *head;
    Node* front;
    Node* back;
    if (!headp || !headp->next) return;
    splitlist(headp, &front, &back);

    mergesort(&front);
    mergesort(&back);

    *head = mergelists(front, back);
}

void splitlist(Node* head, Node** front, Node** back) {
    if (!head || !head->next) {
        *front = head;
        *back = NULL;
    }
    else {
        Node* slow = head;
        Node* fast = head->next;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *front = head;
        *back = slow->next;
        slow->next = NULL;
    }

}

Node* mergelists(Node* a, Node* b) {
    Node* res = new Node();
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) {
        res = a;
        res->next = mergelists(a->next, b);
    }
    else {
        res = b;
        res->next = mergelists(a, b->next);
    }
    return res;
}

void printList(Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

void push(Node** head, int data) {
    Node* n = new Node();
    n->data = data;
    n->next = *head;
    *head = n;
}

int main() {
    struct Node* res = NULL;
    struct Node* a = NULL;
    
    /* Let us create a unsorted linked lists to test the functions
     Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5); 
    push(&a, 20);
    push(&a, 3);
    push(&a, 2); 
    
    printList(a); 
    mergesort(&a);
    cout << endl;
    printList(a);           
    return 0;
}