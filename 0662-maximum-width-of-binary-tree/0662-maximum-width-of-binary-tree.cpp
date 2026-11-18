/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();

            long long a, b;

            // First index of current level
            a = q.front().second;

            for (int i = 0; i < sz; i++) {
                auto temp = q.front();
                q.pop();

                TreeNode* node = temp.first;
                long long idx = temp.second;

                if (i == sz - 1) {
                    b = idx;
                }

                // Normalize indices
                idx -= a;

                if (node->left) {
                    q.push({node->left, 2 * idx + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }

            ans = max(ans, (int)(b - a + 1));
        }

        return ans;
    }
};
