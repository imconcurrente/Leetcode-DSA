class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n*2+1, 0);
        prefix[n] = 1;
        int cnt = n;
        long long ans = 0, prefSum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                prefSum += prefix[cnt];
                cnt++;
                prefix[cnt]++;
            } else {
                cnt--;
                prefSum -= prefix[cnt];
                prefix[cnt]++;
            }
            ans += prefSum;
        }
        return ans;
    }
};