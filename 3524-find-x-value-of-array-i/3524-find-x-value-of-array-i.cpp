class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k);
        vector<long long> dp(k);

        for(int num : nums){
            vector<long long> curr(k); // current freq
            int rem = num % k;

            curr[rem]++;


            for(int j = 0; j < k; j++){
                curr[j * rem % k] += dp[j];
            }

            for(int j = 0; j < k; j++){
                res[j] += curr[j];
            }
            dp = curr;
        }
        return res;
    }
};