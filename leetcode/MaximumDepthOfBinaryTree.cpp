/**
 * source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
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
    // recursive solution
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftTreeHeigth  = maxDepth(root->left);
        int rightTreeHeigth = maxDepth(root->right);
        
        return (leftTreeHeigth > rightTreeHeigth) ? leftTreeHeigth  + 1
                                                  : rightTreeHeigth + 1;
    }
};