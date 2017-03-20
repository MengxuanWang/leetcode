/*
Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode* helper(Iter istart, Iter iend, Iter pstart, Iter pend)
    {
        if (istart == iend) return NULL; 
        int rootVal = *pstart; 
        TreeNode* root = new TreeNode(rootVal); 
        Iter iterroot = find(istart, iend, rootVal);
        root->left = helper(istart, iterroot, pstart+1, pstart+1+(iterroot-istart));
        root->right = helper(iterroot+1, iend, pstart+1+(iterroot-istart), pend);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }
};