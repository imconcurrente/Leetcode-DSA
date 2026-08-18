class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        // case1: k = 1,
        if (k == 1) {
            int maxi = -1;
            for (auto it : mpp) {
                if (it.second == 1) {
                    maxi = max(maxi, it.first);
                }
            }
            return maxi;

            // case2:  k = n
        } else if (k == n) {
            return *max_element(nums.begin(), nums.end());

            // cse3: 1 < k < n
        } else {
            if (mpp[nums[0]] == 1 && mpp[nums[n - 1]] == 1) {
                return max(nums[0], nums[n - 1]);
            } else if (mpp[nums[0]] == 1) {
                return nums[0];
            } else if (mpp[nums[n - 1]] == 1) {
                return nums[n - 1];
            } else {
                return -1;
            }
        }
        return -1;
    }
};