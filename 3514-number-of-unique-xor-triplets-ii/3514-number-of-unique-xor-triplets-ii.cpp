class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        // All possible XORs of two elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }

        vector<int> vis(2048, 0);

        // XOR every pair XOR with every element(Repition allowed)
        for (int i = 0; i < n; i++) {
            for (int x : st) {
                vis[nums[i] ^ x] = 1;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 2048; i++) {
            if (vis[i]) cnt++;
        }

        return cnt;
    }
};