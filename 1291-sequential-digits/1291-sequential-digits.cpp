class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++){
            int val = i;
            for(int j = i+1; j <= 9; j++){
                val = val*10+j;

                if(val >= low && val <= high) ans.push_back(val);

                if(val > high) break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};