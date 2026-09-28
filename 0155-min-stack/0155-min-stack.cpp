//Optimal with T.C -> O(1) and S.C-> O(n), but tricky to understand

class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;

    MinStack() {
    }

    void push(int value) {
        long long val = value;

        if (st.empty()) {
            mini = val;
            st.push(val);
        }
        else if (val < mini) {
            st.push(2 * val - mini);
            mini = val;
        }
        else {
            st.push(val);
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();

        if (x < mini)
            return (int)mini;

        return (int)x;
    }

    int getMin() {
        return (int)mini;
    }
};