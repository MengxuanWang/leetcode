/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res; 
        if (root == NULL) return res;
        queue<TreeNode*> q; 
        q.push(root); 
        TreeNode* cur = NULL;
        while (!q.empty()) {
            int size = q.size(); 
            vector<int> tmp;
            for (int i=0; i<size; i++) {
                cur = q.front();
                q.pop(); 
                tmp.push_back(cur->val);
                if (cur->left) q.push(cur->left); 
                if (cur->right) q.push(cur->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};