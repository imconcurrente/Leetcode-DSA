class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string ans;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == y)
                cnt++;
        }

        while (cnt > 0) {
            ans += y;
            cnt--;
        }

        for (char ch : s) {
            if (ch != y)
                ans += ch;
        }
        return ans;
    }
};