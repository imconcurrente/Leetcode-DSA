class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int hash[256] = {0};
            for (int j = i; j < s.length(); j++) {
                if(hash[s[j]] == 1)
                    break;
                int len = j - i + 1;
                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }
        return maxLen;
    }
};