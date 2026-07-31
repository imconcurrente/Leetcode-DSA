class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> hash(256, 0);

        int l = 0, r = 0;
        int minlen = 10e8;
        int sIdx = -1;
        int cnt = 0;

        int n = s.size(), m = t.size();

        for(int i = 0; i < m; i++) hash[t[i]]++;

        while(r < n){

            if(hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            while(cnt == m){

                int len = r-l+1;

                if(len < minlen){
                    minlen = len;
                    sIdx = l;
                }

                hash[s[l]]++;

                if(hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx,minlen);
    }
};