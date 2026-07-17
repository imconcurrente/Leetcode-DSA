class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0); 
        for(int it :nums)
        freq[it]++;

        vector<long long> cnt(maxi+1,0);

        for(int i = maxi;i >= 1; i--)
        {
            long long curr=0;
            for(int k = i; k <= maxi; k += i) 
            curr += freq[k];
            cnt[i] = curr*(curr-1)/2;
            for(int k = 2*i; k <= maxi; k += i) 
            cnt[i] -= cnt[k];
        }

        for(int i = 1; i <= maxi; i++)
        cnt[i] += cnt[i-1];

        vector<int> res;
        for(auto it :queries)
        res.push_back(lower_bound(cnt.begin(),cnt.end(),it+1)-cnt.begin());
        return res;

        
    }
};