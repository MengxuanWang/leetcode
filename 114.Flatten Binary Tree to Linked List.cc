/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode* root) {
        if (root == NULL) return; 
        flatten(root->left); 
        flatten(root->right); 
        TreeNode* p = root->left; 
        if (p == NULL) return; 
        while (p->right != NULL) {
            p = p->right;
        }
        p->right = root->right; 
        root->right = root->left; 
        root->left = NULL;
    }
};