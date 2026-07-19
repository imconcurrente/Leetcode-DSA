class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string ans = "";

        vector<int> mpp(26, 0);
        for (char ch : s)
            mpp[ch - 'a']++;

        vector<bool> vis(26, 0);

        for (int i = 0; i < n; i++) {
            if (vis[s[i] - 'a'] == 0) {
                while (!ans.empty() && s[i] <= ans.back() &&
                       mpp[ans.back() - 'a']) {
                    vis[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }

                ans += s[i];
                mpp[s[i] - 'a']--;
                vis[s[i] - 'a'] = 1; // update the vis
            } else {
                mpp[s[i] - 'a']--;
            }
        }
        return ans;
    }
};