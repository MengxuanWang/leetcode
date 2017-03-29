/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pHead = new ListNode(-1); 
        pHead->next = head; 
        ListNode* prev = pHead; 
        ListNode* cur = head;
        ListNode* next;
        while (cur) {
            if (cur->val == val) {
                next = cur->next; 
                prev->next = next; 
                free(cur);
                cur = next;
            } else {
                prev = cur; 
                cur = cur->next;
            }
        }
        return pHead->next;
    }
};