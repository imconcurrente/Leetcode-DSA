class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // [1,4,5,7,8]

        if(n <= 3) return 0;

        int a = abs(nums[n-1] - nums[2]); // changing two smallest;
        int b = abs(nums[n-3] - nums[0]); // changing two largest;
        int c = abs(nums[n-2] - nums[1]); // changing two ends;

        return min({a,b,c}); 
    }
};