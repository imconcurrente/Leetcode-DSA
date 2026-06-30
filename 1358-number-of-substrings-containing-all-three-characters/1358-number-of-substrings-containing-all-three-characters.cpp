class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int j = 0;

        int a = 0, b = 0,  c = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            a++;

            else if(s[i] == 'b')
            b++;

            else c++;

            while(a > 0 && b > 0 && c > 0)
            {
                cnt += (n - i);
                if(s[j] == 'a')
                a--;

                else if(s[j] == 'b')
                b--;

                else c--;
                j++;
            }
        }
        return cnt;
    }
};