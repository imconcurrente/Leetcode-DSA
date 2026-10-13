class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &it : nums){
            if(it < 0) it = -it;
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low =0, hi = n-1;
        long long sum = 0;
        while(low < hi){
            sum += (1ll * nums[hi] * nums[hi] - (1ll * nums[low] * nums[low]));
            low++;
            hi--;
        }
        if(low == hi){
            sum += (1ll * nums[low] * nums[low]); // if same square it ones
        }
        return sum;
    }
};