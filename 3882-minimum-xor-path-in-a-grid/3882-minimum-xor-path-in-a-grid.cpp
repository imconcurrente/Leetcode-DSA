class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<unordered_set<int>> dp(m);

        // start
        dp[0].insert(grid[0][0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) continue;

                unordered_set<int> curr;

                for (int val : dp[j]) {
                    curr.insert(val ^ grid[i][j]);
                }

                
                if (j > 0) {
                    for (int val : dp[j-1]) {
                        curr.insert(val ^ grid[i][j]);
                    }
                }

                dp[j] = curr;
            }
        }

        int res = INT_MAX;
        for (int val : dp[m-1]) {
            res = min(res, val);
        }

        return res;
    }
};