/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* findNext(TreeLinkNode* root) {
        while (root != NULL) {
            if (root->left != NULL) return root->left; 
            if (root->right != NULL) return root->right;
            root = root->next;
        }
        return NULL;
    }
    void connect(TreeLinkNode *root) {
        TreeLinkNode* leftend = root; 
        while (leftend != NULL) {
            TreeLinkNode* cur = leftend; 
            while (cur != NULL) {
                TreeLinkNode* next = findNext(cur->next); 
                if (cur->right) {
                    cur->right->next = next; 
                    next = cur->right;
                }
                if (cur->left) {
                    cur->left->next = next;
                }
                cur = cur->next;
            }
            leftend = findNext(leftend);
        }
    }
};