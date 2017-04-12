/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int calcuTreeSize(TreeNode* root) {
        if (root == NULL) return 0; 
        return 1 + calcuTreeSize(root->left) + calcuTreeSize(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int leftSize = calcuTreeSize(root->left); 
        if (k == leftSize + 1) return root->val; 
        if (k <= leftSize) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k-leftSize-1);
        }
    }
};