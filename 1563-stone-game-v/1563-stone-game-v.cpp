class Solution {
public:
    int solve(vector<int>&nums, int i, int j, vector<vector<int>>&dp)
    {
        if(i >= j)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int totalSum = 0;

        for(int k = i; k <= j; k++)
        totalSum += nums[k];

        int ans = 0;
        int leftSum = 0;

        for(int k = i; k < j; k++)
        {
            leftSum += nums[k];
            int rightSum = totalSum - leftSum;

            if(leftSum < rightSum)
            ans = max(ans,leftSum + solve(nums, i, k, dp));

            else if(rightSum < leftSum) ans = max(ans, rightSum + solve(nums, k+1, j, dp));

            else ans = max({ans, leftSum + solve(nums, i, k, dp), rightSum + solve(nums, k+1, j, dp)});
        }

        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(stoneValue, 0, n-1, dp);
    }
};