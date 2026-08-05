class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto& it : invocations) {
            graph[it[0]].push_back(it[1]);
        }

        vector<int> vis(n, 0);

        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (int v : graph[u]) {
                if (!vis[v])
                    dfs(v);
            }
        };

        dfs(k);

        for (auto& it : invocations) {
            int u = it[0];
            int v = it[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};