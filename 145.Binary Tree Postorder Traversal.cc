/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk; 
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        vector<int> res; 
        while (true) {
            while (cur) {
                stk.push(cur); 
                cur = cur->left;
            }
            if (stk.empty()) break; 
            cur = stk.top(); 
            if (cur->right && cur->right != prev) {
                cur = cur->right;
            } else {
                stk.pop(); 
                res.push_back(cur->val);
                prev = cur;
                cur = NULL;
            }
        }
        return res;
    }
};