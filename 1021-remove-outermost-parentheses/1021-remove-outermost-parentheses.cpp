class Solution {
public:
    string removeOuterParentheses(string s) {
        int j = 0;
        int cnt = 0;
        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            cnt++;

            else cnt--;

            if(cnt == 0)
            {
                ans += s.substr(j+1, i - j - 1);
                j = i + 1;
            }
        }
        return ans;
    }
};