/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    typedef vector<int>::iterator Iter;
    TreeNode* helper(Iter istart, Iter iend, Iter pstart, Iter pend) {
        if (istart == iend) return NULL; 
        int rootVal = *prev(pend); 
        Iter rootIter = find(istart, iend, rootVal); 
        TreeNode* root = new TreeNode(rootVal); 
        root->left = helper(istart, rootIter, pstart, pstart+(rootIter - istart));
        root->right = helper(rootIter+1, iend, pstart+(rootIter-istart), prev(pend));
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};