class DSU{
    public:
    vector<int>parent, size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
        parent[i] = i;
    }

    int find(int node)
    {
        if(parent[node] == node)
        return node;

        return parent[node] = find(parent[node]);
    }

    void ubs(int u, int v)
    {
        int up = find(u);
        int vp = find(v);

        if(up == vp)
        return;

        if(size[up] > size[vp])
        {
            size[up] += size[vp];
            parent[vp] = up;
        }

        else
        {
            size[vp]+= size[up];
            parent[up] = vp;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size(), 0);

        DSU ds(n);

        for(int i = 0; i < n-1; i++)
        {
            if(nums[i+1] - nums[i] <= maxDiff)
            ds.ubs(i, i+1);
        }

        for(int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            if(ds.find(u) == ds.find(v))
            ans[i] = 1;
        }

        return ans;
    }
};