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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSum(root, maxi);
        return maxi;
    }

    int maxPathSum(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int lSum = max(0, maxPathSum(root->left, maxi)); // if we get negative sum, we wil consider it as 0 i.e max(0, ___)

        int rSum = max(0, maxPathSum(root->right, maxi));

        maxi = max(maxi, lSum + rSum + root->val);

        return max(lSum, rSum) + root->val;

    }
};