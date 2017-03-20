/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
// class Solution {
// public:
//     struct Result {
//         bool isbalanced; 
//         int height;
//         Result(bool b=false, int h=0): isbalanced(b), height(h) {}
//     };
//     Result helper(TreeNode* root) {
//         if (root == NULL) {
//             return Result(true, 0);
//         }
//         Result r1 = helper(root->left); 
//         Result r2 = helper(root->right); 
//         Result r;
//         r.height = max(r1.height, r2.height) + 1;
//         if (r1.isbalanced && r2.isbalanced && abs(r1.height-r2.height)<=1) {
//             r.isbalanced = true;
//         }
//         return r;
//     }
//     bool isBalanced(TreeNode* root) {
//         Result r = helper(root); 
//         return r.isbalanced;
//     }
// };

// solution2
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right); 
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1; 
    } 
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};