class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26, 0);
        for (char ch : word) {
            hash[ch - 'a']++;
        }
        sort(hash.begin(), hash.end(), greater<int>()); // sort in descending order

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] == 0) {
                break;
            }
            ans += hash[i] * (i / 8 + 1);
        }

        return ans;
    }
};