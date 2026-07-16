class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        
        // Two pointers
        int l = 0;
        int r = n-1;
        long long sum = 0;
        
        while(l < r){
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};