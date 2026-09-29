class Solution {
public:
    bool dfs(int i, int j, int curr, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(grid[i][j] == '(')
            curr++;
        else curr--;

        if(curr < 0) return false;

        if(i == grid.size() - 1 && j == grid[0].size() - 1) return curr == 0;
        if(dp[i][j][curr] != -1) return dp[i][j][curr];
        bool res = false;
        if(i < grid.size() - 1)
            res = dfs(i+1, j, curr, grid, dp);
        if(res)
            return dp[i][j][curr] = res;
        if(j < grid[0].size() - 1)
            res = dfs(i, j + 1, curr, grid, dp);
        return dp[i][j][curr] = res;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<vector<int>>> dp(i, vector<vector<int>>(j, vector<int>(i + j + 1, -1)));
        return dfs(0, 0, 0, grid, dp); 
    }
};