/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> tmp;
        if (start > end) {
            tmp.push_back(NULL);
            return tmp;
        } 
        for (int val=start; val<=end; val++) {
            vector<TreeNode*> lefts = dfs(start, val-1); 
            vector<TreeNode*> rights = dfs(val+1, end); 
            for (int i=0; i<lefts.size(); i++) {
                for(int j=0; j<rights.size(); j++) {
                    TreeNode* root = new TreeNode(val); 
                    root->left = lefts[i];
                    root->right = rights[j];
                    tmp.push_back(root);
                }
            }
        }
        return tmp;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res; 
        if (n == 0) return res; 
        res = dfs(1, n);
        return res;
    }
};