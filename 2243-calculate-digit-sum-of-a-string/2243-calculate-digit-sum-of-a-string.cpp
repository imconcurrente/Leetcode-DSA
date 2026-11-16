class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        while (n > k) {
            string ans = "";
            for (int i = 0; i < n; i += k) {
                string group = s.substr(i, k);
                int sum = 0;
                for (auto it : group) {
                    sum += it - '0';
                }
                ans += to_string(sum);
            }
            s=ans;
            n = s.length();
        }
        return s;
    }
};