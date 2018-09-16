/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
*/

#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len=1;
        ListNode* tail=head;
        ListNode* newH=head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next=head;
        k = k%len;
        for (int i=0; i<len-k; i++) {
            tail = tail->next;
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};
