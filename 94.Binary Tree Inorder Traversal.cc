/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; 
        vector<int> res; 
        TreeNode* cur = root;
        while(true) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty()) break;
            cur = s.top();
            s.pop();
            res.push_back(cur->val); 
            cur = cur->right;
        }
        return res;
    }
};