/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* p = pHead;
        ListNode*prev = head;
        bool isDuplicates = false;
        while(prev->next != NULL) {
            ListNode* cur = prev->next;
            if (cur->val != prev->val) {
                if (!isDuplicates) {
                    p->next = prev;
                    p = p->next;
                }
                isDuplicates = false;
            } else {
                isDuplicates = true;
            }
            prev = cur;
        }
        if (!isDuplicates) {
            p->next = prev; 
            p = p->next;
        }
        p->next = NULL;
        return pHead->next;
    }
};