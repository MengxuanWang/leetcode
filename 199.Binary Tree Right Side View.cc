/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; 
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root); 
        TreeNode* cur;
        while (!q.empty()) {
            int size = q.size(); 
            for (int i=0; i<size; i++) {
                cur = q.front(); 
                q.pop(); 
                if (i == 0) res.push_back(cur->val);
                if (cur->right) q.push(cur->right); 
                if (cur->left) q.push(cur->left);
            }
        }
        return res;
    }
};