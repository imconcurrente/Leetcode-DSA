class Solution {
public:
    bool stoneGameIX(vector<int>& st) {
        vector<int> cnt(3, 0);

        for (auto val : st) 
        cnt[val % 3]++;
        
        if (cnt[0] % 2 == 0) 
        return (min(cnt[1], cnt[2]) >= 1);

        return abs(cnt[1] - cnt[2]) >= 3;
    }
};