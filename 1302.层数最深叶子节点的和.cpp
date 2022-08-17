/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> qa;
        int res = 0;
        qa.push(root);
        while(!qa.empty()) {
            int len = qa.size();
            int d = 0;
            for(int i = 0; i < len; i++) {
                auto x = qa.front();
                qa.pop();
                if(x->left == nullptr && x->right == nullptr) {
                    d += x->val;
                    continue;
                }
                if(x->left != nullptr) {
                    qa.push(x->left);
                }
                if(x->right != nullptr) {
                    qa.push(x->right);
                }
            }
            if(qa.empty()) {
                res = d;
            }
        }
        return res;
    }
};
// @lc code=end

