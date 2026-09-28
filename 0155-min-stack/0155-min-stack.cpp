// Best optimal approach 
class MinStack {
public:
    stack<int> st;
    stack<int> mini;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if (mini.empty()) {
            mini.push(value);
        }
        else {
             mini.push(min(value, mini.top()));
        }
    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};