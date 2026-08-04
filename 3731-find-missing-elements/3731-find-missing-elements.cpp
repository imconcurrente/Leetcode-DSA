class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();

        int l = nums[0];
        int r = nums[n-1];

        map<int,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(int i = l; i <= r; i++){
            if(mpp.find(i) == mpp.end()){
                ans.push_back(i);
            }  
        }
        return ans;
    }
};