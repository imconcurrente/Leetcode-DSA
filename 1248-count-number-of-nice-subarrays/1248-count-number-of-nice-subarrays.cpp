class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        if (k < 0)
            return 0;

        int l = 0, r = 0, cnt = 0, sum = 0;

        while (r < n) {

            sum += nums[r] % 2; // odd intege -> 1
                                // even integer -> 0

            // After this conversion to binary array it is exactly same as
            // problem 930. Binary Subarrays With Sum

            while (sum > k) {
                sum -= nums[l] % 2;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};