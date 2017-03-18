/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k <= 0) return head; 
        ListNode* fast = head;
        ListNode* slow = head; 
        int count = 0;
        while (fast!=NULL) {
            count++;
            fast = fast->next;
        }
        k = k % count;
        fast = head;
        int i = 0;
        while (i < k) {
            if (fast->next == NULL) break; 
            fast = fast->next; 
            i++;
        }
        if (i < k) return head; 
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head; 
        ListNode* p = slow->next;
        slow->next = NULL;
        return p;
    }
};