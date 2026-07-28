class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxfreq = 0, maxlen = 0;
        map<char, int> mpp;

        while (r < n) {
            mpp[s[r]]++;

            maxfreq = max(maxfreq, mpp[s[r]]);

            if ((r - l + 1) - maxfreq > k) {
                mpp[s[l]]--;
                maxfreq = 0;

                for (auto x : mpp) {
                    maxfreq = max(maxfreq, x.second);
                }
                l++;
            }
             if ((r - l + 1) - maxfreq <= k) {
                    maxlen = max(maxlen, (r - l + 1));
                }
                r++;
        }
        return maxlen;
    }
};