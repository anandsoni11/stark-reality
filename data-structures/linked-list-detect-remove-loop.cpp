#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
typedef struct Node Node;

Node* detectloop(Node* head) {
    if (!head || !head->next) return NULL;
    Node* loopnode = NULL;
    Node* slow = head;
    Node* fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next) {
        if (slow == fast) return fast;
        slow = slow->next;
        fast = fast->next->next;
    }
    return loopnode;
}

void removeloop(Node* loopnode, Node* head) {
    Node* slow = head;
    Node* fast = loopnode;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* newNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    return n;
}

int main() {
    Node *head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* loopnode = detectloop(head);
    bool loop = loopnode ? 1 : 0;
    cout << loop << endl;
    
    removeloop(loopnode, head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}