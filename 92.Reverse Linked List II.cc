/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    void reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev; 
            prev = cur;
            cur = next;
        }
    }
    ListNode* findKth(ListNode* head, int k) {
        for (int i=0; i<k; i++) {
            if (head == NULL) return NULL;
            head = head->next;
        }
        return head;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* prev_mth = findKth(pHead, m-1);
        ListNode* nth = findKth(pHead, n);
        ListNode* nth_next = nth->next;
        ListNode* mth = prev_mth->next; 
        nth->next = NULL;
        reverse(mth);
        prev_mth->next = nth;
        mth->next = nth_next;
        return pHead->next;
    }
};