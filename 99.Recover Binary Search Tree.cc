/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s; 
        TreeNode* prev = NULL;
        TreeNode* cur = root; 
        TreeNode* first = NULL;
        TreeNode* second = NULL; 
        while (true) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty()) break; 
            cur = s.top();
            s.pop(); 
            if (prev != NULL && prev->val > cur->val) {
                if (first == NULL) {
                    first = prev; 
                    second = cur;
                } else {
                    second = cur;
                }
            }
            prev = cur; 
            cur = cur->right;
        }
        int tmp = first->val; 
        first->val = second->val;
        second->val = tmp;
    }
};