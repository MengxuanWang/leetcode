/*
	Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeSort(ListNode*head1, ListNode* head2) {
        ListNode* pHead = new ListNode(-1); 
        ListNode* p = pHead;
        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                p->next = head1; 
                head1 = head1->next;
            } else {
                p->next = head2; 
                head2 = head2->next;
            }
            p = p->next;
        }
        p->next = (head1 != NULL ? head1 : head2); 
        return pHead->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head; 
        ListNode* mid = getMiddleNode(head); 
        ListNode* next = mid->next; 
        mid->next = NULL; 
        return mergeSort(sortList(head), sortList(next));
    }
};