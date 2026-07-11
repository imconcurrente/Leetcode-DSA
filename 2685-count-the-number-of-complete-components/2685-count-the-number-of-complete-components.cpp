class DSU{
    public:
    vector<int>parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int fup(int u)
    {
        if(parent[u] == u)
        return u;

        return parent[u] = fup(parent[u]);
    }

    void ubs(int u, int v)
    {
        int up = fup(u);
        int vp = fup(v);

        if(up == vp)
        return;

        if(size[up] > size[vp])
        {
            size[up] += size[vp];
            parent[vp] = up;
        }
        else
        {
            size[vp] += size[up];
            parent[up] = vp;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
    DSU d(n);

    for(auto &e : edges)
        d.ubs(e[0], e[1]);

    unordered_map<int,int> nodes, edgeCnt;

    for(int i = 0; i < n; i++)
        nodes[d.fup(i)]++;

    for(auto &e : edges)
        edgeCnt[d.fup(e[0])]++;

    int ans = 0;

    for(auto &it : nodes)
    {
        int root = it.first;
        int cnt = it.second;

        if(edgeCnt[root] == cnt * (cnt - 1) / 2)
            ans++;
    }

    return ans;
    }
};