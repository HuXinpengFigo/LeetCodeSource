/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 * 
 * 主要方法：
 *      典型的DFS问题，使用递归可以完成。
 *      在写递归的时候，要反着写，首先写如何增加height，之后再倒回来继续写如何进入递归。
 * 
 */

// @lc code=start
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return checkBalanced(root,height);
    }
    bool checkBalanced(TreeNode* root, int& height) {
        if(!root) {
            height = 0;
            return true;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        if(!checkBalanced(root->left, leftHeight))  return false; //再倒过来想怎么进入递归
        if(!checkBalanced(root->right, rightHeight)) return false;
        if(abs(leftHeight - rightHeight) > 1) return false;
        height = max(leftHeight, rightHeight) + 1;  //先写height更新的方法
        return true;
    }
};
// @lc code=end

