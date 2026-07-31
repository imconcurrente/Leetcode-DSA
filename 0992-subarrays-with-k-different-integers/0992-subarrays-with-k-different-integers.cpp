class Solution {
public:

    int atmost(vector<int>& nums, int k){
        // for <= k
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        map <int, int> mpp;

        while(r < n){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;

                if(mpp[nums[l]] == 0){
                    
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums,k-1);
    }
};