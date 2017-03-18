/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ahead = new ListNode(0);
        ListNode* bhead = new ListNode(0);
        ListNode* atile = ahead;
        ListNode* btile = bhead;
        while (head != NULL) {
            if (head->val < x) {
                atile->next = head;
                atile = atile->next;
            } else {
                btile->next = head;
                btile = btile->next;
            }
            head = head->next;
        }
        atile->next = bhead->next;
        btile->next = NULL;
        return ahead->next;
    }
};