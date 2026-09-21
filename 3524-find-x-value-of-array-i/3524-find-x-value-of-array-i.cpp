class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k);
        int hash[5] = {0};

        for (auto& num : nums) {
            num %= k;
            int curr[5] = {0}; //current freq.

            curr[num] = 1;

            for (int x = 0; x < k; x++)
                curr[x * num % k] += hash[x];

            for (int x = 0; x < k; x++) {
                hash[x] = curr[x];
                res[x] += hash[x];
            }
        }

        return res;
    }
};