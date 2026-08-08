class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int j = m - 1;
        vector<int> last(m, -1);

        for (int i = n - 1; i >= 0; i--) {
            if (j < 0)
                break;

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        j = 0;
        vector<int> ans;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (j == m)
                break;

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else {
                if (cnt == 0 && (j + 1 == m || i < last[j + 1])) {
                    cnt++;
                    ans.push_back(i);
                    j++;
                }
            }
        }

        if (j < m)
            return {};

        return ans;
    }
};