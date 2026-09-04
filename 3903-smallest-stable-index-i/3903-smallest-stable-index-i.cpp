class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int maxiEle=*max_element(nums.begin(),nums.begin()+i);
            int miniEle=*min_element(nums.begin()+i,nums.end());
            int instabilityScore = maxiEle-miniEle;
            if(instabilityScore<=k){
                return i;
            }
        }
        return -1;
    }
};