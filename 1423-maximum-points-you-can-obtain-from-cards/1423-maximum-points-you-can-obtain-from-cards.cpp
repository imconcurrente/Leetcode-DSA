class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lSum = 0, rSum = 0, maxSum = 0;

        for (int i = 0; i <= k - 1; i++) {
            lSum = lSum + nums[i];
        }
         maxSum = lSum;

        int rightIdx = n - 1;
        
        for (int i = k - 1; i >= 0; i--) {
            lSum = lSum - nums[i];
            rSum = rSum + nums[rightIdx];
            rightIdx = rightIdx - 1;
            maxSum = max(maxSum, lSum + rSum);
        }    
        return maxSum;
    }
};