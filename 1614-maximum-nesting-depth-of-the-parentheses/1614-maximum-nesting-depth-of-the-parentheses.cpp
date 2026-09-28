class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0, depth = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                depth++;
                ans = max(depth, ans);
            }else if(s[i] == ')'){
                depth--;
            }
        }
        return ans;
    }
};