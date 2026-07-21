class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ans = 0;
        int zero = 0;
        int cnt = 0;

        vector<int> arr;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(cnt != 0)
                arr.push_back(cnt);
                cnt = 0;
                ans++;
            }
            else{
                cnt++;
            }
        }

        if(cnt != 0)
        arr.push_back(cnt);

        if(arr.size() == 0) return ans;

        for(int i = 0; i < arr.size()-1; i++){
            zero = max(zero, arr[i] + arr[i+1]);
        }
        ans += zero;
        return ans;
    }
};