/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pHead = new ListNode(0); 
        pHead->next = head; 
        ListNode*q = pHead; 
        ListNode*p;
        while (q->next!=NULL && q->next->next!=NULL) {
            p = q->next->next; 
            q->next->next = p->next; 
            p->next = q->next; 
            q->next = p; 
            q = q->next->next;  // note 
        }
        q = pHead->next;
        free(pHead);
        return q;
    }
};