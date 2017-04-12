/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        int leftlen = 0, rightlen = 0; 
        TreeNode* cur = root; 
        while (cur) {
            leftlen ++; 
            cur = cur->left;
        }
        cur = root; 
        while (cur) {
            rightlen ++;
            cur = cur->right;
        }
        if (leftlen == rightlen) return (1 << leftlen) -1; 
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};