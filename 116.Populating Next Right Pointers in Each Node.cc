/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
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
    // void connect(TreeLinkNode *root) {
    //     if (root == NULL) return; 
    //     queue<TreeLinkNode*> q; 
    //     q.push(root); 
    //     while(!q.empty()) {
    //         int size = q.size(); 
    //         TreeLinkNode* prev = NULL; 
    //         TreeLinkNode* cur = NULL;
    //         for (int i=0; i<size; i++) {
    //             cur = q.front();
    //             q.pop(); 
    //             if (prev) prev->next = cur; 
    //             prev = cur; 
    //             if (cur->left) q.push(cur->left); 
    //             if (cur->right) q.push(cur->right);
    //         }
    //         cur->next = NULL;
    //     }
    // }
    
    // solution 2: using constant extra space
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode* leftend = root; 
        while(leftend != NULL) {
            TreeLinkNode* cur = leftend; 
            while (cur != NULL) {
                if (cur->left == NULL) break; 
                cur->left->next = cur->right; 
                if (cur->next != NULL) 
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            leftend = leftend->left;
        }
    }
};