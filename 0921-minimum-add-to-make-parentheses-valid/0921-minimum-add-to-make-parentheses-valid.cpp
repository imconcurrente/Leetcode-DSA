class Solution {
public:
    int minAddToMakeValid(string s) {
        // empty string
        if (s.length() == 0) {
            return 0; 
        }
        stack<int> st;
        int move = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    st.push('(');
                    move++;
                }
                st.pop();
            }
        }
        if (!st.empty()) {
            // add remaining opening brackets
            move += st.size();
        }
        return move;
    }
};