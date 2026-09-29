class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int depth = 0; 
        int ans = 0;

        for(auto ch : s){
            if(ch == '('){
                depth++;
                ans = max(ans, depth);
                st.push(ans);
            }
            else if(ch == ')'){
                depth--;
            }
        }
        return ans;
    }
};