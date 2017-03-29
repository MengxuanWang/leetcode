/*
	Sort a linked list using insertion sort.
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
    ListNode* findInsertPos(ListNode* head, int val) {
        ListNode* prev = head; 
        ListNode* cur = prev->next; 
        while (cur && cur->val <= val) {
            prev = cur; 
            cur = cur->next;
        }
        return prev;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* pHead = new ListNode(-1); 
        pHead->next = NULL; 
        ListNode* next;
        ListNode* new_next, * prev;
        while (head) {
            next = head->next;
            prev = findInsertPos(pHead, head->val); 
            head->next = prev->next; 
            prev->next = head; 
            head = next;
        }
        return pHead->next;
    }
};