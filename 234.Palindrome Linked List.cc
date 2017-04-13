/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; 
        ListNode* next = NULL; 
        while (head) {
            next = head->next; 
            head->next = prev; 
            prev = head; 
            head = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next==NULL) return true; 
        ListNode* fast = head;
        ListNode* slow = head; 
        while (fast->next && fast->next->next) {
            fast = fast->next->next; 
            slow = slow->next;
        }
        ListNode *head2 = slow->next; 
        slow->next = NULL; 
        head2 = reverseList(head2); 
        while (head && head2) {
            if (head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};