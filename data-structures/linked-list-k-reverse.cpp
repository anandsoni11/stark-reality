#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node Node;

Node* reverseK(Node* head, int k) {
    Node* cur = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while (cur && count < k) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if (next) {
        head->next = reverseK(next, k);
    }

    return prev;
}

Node* push(Node* head, int data) {
    Node* n = new Node();
    n->data = data;
    n->next = head;
    head = n;
    return head;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->next;
    }
}    

int main(void) {
    struct Node* head = NULL;
    head = push(head, 9);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 6);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);           
 
    printList(head);
    cout << endl;
    head = reverseK(head, 3);
    printList(head);
 
    return(0);
}