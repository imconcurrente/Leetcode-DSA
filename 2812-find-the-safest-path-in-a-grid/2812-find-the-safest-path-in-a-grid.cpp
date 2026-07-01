class Solution {
public:
    bool haspath(vector<vector<int>>& grid, int v){
        int n = grid.size();
        if (grid[0][0] < v || grid[n-1][n-1] < v) {
            return false;
        }
        
        queue<pair<int, int>> q;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        q.push({0, 0});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        
        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();
            
            if(x == n-1 && y == n-1) return true;
            
            for (int i = 0; i < 4; ++i) {
                int nr = x + dx[i];
                int nc = y + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    
                    if (grid[nr][nc] >= v) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        // Bfs 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Calculating shortest distance 
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        // Binary search for the maximum safeness factor
        int low = 0;
        int high = dist[0][0]; 
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(haspath(dist, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};