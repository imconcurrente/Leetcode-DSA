class Solution {
public:
    string ans = "";

    bool dfs(int idx, bool greater, string &curr, vector<int> &freq, string &target) {
        int n = target.size();

        if (idx == n) {
            if (greater) 
                ans = curr;   //final valid permutation save karo

            return greater;    //strict greater required
        }

        if (greater) {
            string res = curr;
            for (int c = 0; c < 26; c++) 
                res.append(freq[c], char('a' + c));
            
            ans = res;
            return true;
        }

        for (int c = target[idx] - 'a'; c < 26; c++) {
            if (freq[c] == 0) 
                continue;

            freq[c]--;
            curr.push_back(char('a' + c));

            if (dfs(idx + 1, greater || c > (target[idx] - 'a'), curr, freq, target)) 
                return true;
            

            curr.pop_back();
            freq[c]++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char ch : s) 
            freq[ch - 'a']++;

        string curr = "";
        if (dfs(0, false, curr, freq, target)) 
            return ans;

        return "";
    }
};