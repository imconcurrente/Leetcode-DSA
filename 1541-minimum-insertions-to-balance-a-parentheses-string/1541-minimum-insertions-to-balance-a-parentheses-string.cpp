class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            cnt+=1;

            else
            {
                cnt-=1;
                if(i + 1 < s.size() && s[i+1] == ')')
                i++;

                else ans++;
            }

            if(cnt < 0)
            {
                cnt++;
                ans++;
            }
        }

        return ans + cnt*2;
    }
};