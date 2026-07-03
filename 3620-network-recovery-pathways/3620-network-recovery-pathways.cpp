class Solution {
private:
    vector<vector<pair<int,int>>> adj;
    vector<bool> present;
    long long total_distance;
    stack<int> st;
    vector<int> vis;
    const long long INF = 4e18;

public:
    void dfs(int node){
        if(vis[node]) return;
        vis[node] = 1;

        for(auto &it : adj[node]){
            dfs(it.first);
        }

        st.push(node);
    }

    bool solve(int limit){
        vector<long long> dist(vis.size(), INF);
        stack<int> order = st;

        dist[0] = 0;

        while(!order.empty()){
            int node = order.top();
            order.pop();

            if(dist[node] == INF || !present[node]) continue;

            for(auto &it : adj[node]){
                int nxt = it.first;
                int wt  = it.second;

                if(!present[nxt] || wt < limit) continue;

                dist[nxt] = min(dist[nxt], dist[node] + wt);
            }
        }

        return dist.back() <= total_distance;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        adj.resize(n);
        vis.assign(n, 0);

        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        present = online;
        total_distance = k;

        for(int i = 0; i < n; i++){
            if(!vis[i]) dfs(i);
        }

        int low = 0;
        int high = 1e9;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(solve(mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
};