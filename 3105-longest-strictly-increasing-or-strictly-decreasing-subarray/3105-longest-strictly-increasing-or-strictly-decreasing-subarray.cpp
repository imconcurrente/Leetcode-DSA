
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int inc = 0;
        int dec = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, i - inc);
                inc = i;
            }

            if (nums[i] >= nums[i - 1]) {
                ans = max(ans, i - dec);
                dec = i;
            }
        }

        ans = max(ans, n - inc);
        ans = max(ans, n - dec);

        return ans;
    }
};