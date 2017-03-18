/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* merge(vector<ListNode*>&lists, int l, int r) {
        if (l == r) return lists[l]; 
        int m = (l + r) / 2;
        ListNode *head1 = merge(lists, l, m); 
        ListNode *head2 = merge(lists, m+1, r); 
        ListNode* pHead = new ListNode(0);
        ListNode* q = pHead;
        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                q->next = head1; 
                head1 = head1->next; 
            } else {
                q->next = head2;
                head2 = head2->next;
            }
            q = q->next;
        }
        if (head1 == NULL) q->next = head2;
        else q->next = head1;
        q = pHead->next;
        free(pHead); 
        return q;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return NULL;
        return merge(lists, 0, size-1);
    }
};