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
private:
    void helper(TreeNode *node, int maxVal, int &cnt) {
        if (!node) return;

        if (maxVal <= node->val) {
            cnt++;
        }
        maxVal = max(node->val, maxVal);
        helper(node->left, maxVal, cnt);
        helper(node->right, maxVal, cnt);
    }

public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        helper(root, INT_MIN+2, cnt);
        return cnt;
    }
};