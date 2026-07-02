class Solution {
public:
    int nRow[4] = {-1, 0, 1, 0};
    int nCol[4] = {0, 1, 0, -1};

    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<int>>& grid, int i, int j, int health)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;

        health -= grid[i][j];

        if(health <= 0)
            return false;

        if(i == n - 1 && j == m - 1)
            return true;

        if(dp[i][j][health] != -1)
            return dp[i][j][health];

        int val = grid[i][j];
        grid[i][j] = -1;

        bool ans = false;

        for(int k = 0; k < 4; k++)
        {
            int r = i + nRow[k];
            int c = j + nCol[k];

            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != -1)
            {
                ans |= solve(grid, r, c, health);
                if(ans) break;
            }
        }

        grid[i][j] = val;

        return dp[i][j][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n,
                  vector<vector<int>>(m,
                  vector<int>(health + 1, -1)));

        return solve(grid, 0, 0, health);
    }
};