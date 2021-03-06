/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode*p = head;
        ListNode*prev = head;
        while(prev->next != NULL) {
            ListNode* cur = prev->next;
            if(cur->val != prev->val) {
                p->next = cur;
                p = p->next;
            }
            prev = cur;
        }
        p->next = NULL;
        return head;
    }
};