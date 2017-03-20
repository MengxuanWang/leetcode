/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // solution 1
    // TreeNode* sortedListToBST(ListNode* head) {
    //     if (head == NULL) return NULL;
    //     if (head->next == NULL) return new TreeNode(head->val);
        
    //     ListNode* fast = head; 
    //     ListNode* slow = head; 
    //     ListNode* prev = NULL; 
    //     while (fast!=NULL && fast->next!=NULL) {
    //         prev = slow; 
    //         slow = slow->next; 
    //         fast = fast->next->next;
    //     }
    //     TreeNode* root = new TreeNode(slow->val); 
    //     prev->next = NULL; 
    //     root->left = sortedListToBST(head); 
    //     root->right = sortedListToBST(slow->next);
    //     return root;
    // }
    
    // solution 2
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL; 
        int size = getListSize(head);
        return helper(head, size);
    }
    int getListSize(ListNode* head) {
        int size = 0; 
        while (head != NULL) {
            size ++;
            head = head->next;
        }
        return size;
    }
    
    TreeNode* helper(ListNode*& head, int size) {
        if (size == 0) return NULL;
        TreeNode* root = new TreeNode(0); 
        root->left = helper(head, size/2); 
        root->val = head->val; 
        head = head->next; 
        root->right = helper(head, size - size/2 - 1);
        return root;
    }
};