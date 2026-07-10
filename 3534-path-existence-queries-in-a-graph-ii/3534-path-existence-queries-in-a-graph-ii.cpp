class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        vector<pair<int,int>> arr;

        for(int i = 0; i < n ; i++)
            arr.push_back({nums[i],i});

        sort(arr.begin(), arr.end());

        vector<int> temp(n), pos(n);


        for(int i = 0; i < n; i++)
        {
            temp[i] = arr[i].first;
            pos[arr[i].second] = i; 

        }

        int mx = log2(n) + 1;


        vector<vector<int>> next(mx, vector<int>(n,-1));

        for(int i = 0; i < n; i++)
        {


            int ind = upper_bound(temp.begin(), temp.end(),
                        temp[i] + maxDiff) - temp.begin() - 1;

            next[0][i] = ind;

        }



        for(int i = 1; i < mx; i++)
        {
            for(int j = 0; j < n; j++)
            {
                next[i][j] = next[i-1][next[i-1][j]];

            }

        }

        vector<int> ans;

        for(vector<int> q: queries)
        {
            int u = q[0];
            int v = q[1];

            int a = pos[u];
            int b = pos[v];

            if(a == b)
                ans.push_back(0);
            else  
            {
                if(a > b)
                    swap(a,b);

                int curr = 0;


                for(int k = mx - 1; k >= 0; k--)
                {
                    if(next[k][a] < b)
                    {
                        curr += (1<<k);
                        a = next[k][a];

                    }

                }

                if(next[0][a] >= b)
                    ans.push_back(curr + 1);
                else  
                {
                    ans.push_back(-1);

                }

            }

        }

        return ans;
        
    }
};