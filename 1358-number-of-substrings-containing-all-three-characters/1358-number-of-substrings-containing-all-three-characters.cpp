class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3, 0);
        int l = 0;
        int cnt = 0;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;

            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
                cnt += (n - i);

                arr[s[l] - 'a']--;
                l++;
            }
        }
        return cnt;
    }
};