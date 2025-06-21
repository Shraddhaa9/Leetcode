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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<int> pq;
        q.push(root);
        pq.push(root->val);

        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if(curr->left) {
                q.push(curr->left);
                pq.push(curr->left->val);
                if (pq.size() > k) pq.pop();
            }

            if(curr->right) {
                q.push(curr->right);
                pq.push(curr->right->val);
                if (pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};