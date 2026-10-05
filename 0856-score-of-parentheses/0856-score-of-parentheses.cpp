class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;
        st.push(0); // intial score;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(0);
            }else{
                int inside = st.top();
                st.pop();
                int curr = 0; 

                if(inside == 0){
                    curr = 1;
                }else{
                    curr = 2*inside; // AB
                }
                st.top() += curr; // A+B
            }
        }
        return st.top();
    }
};