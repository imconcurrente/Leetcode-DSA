class StockSpanner {
private:
    int idx;
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        idx = -1;
        while (!st.empty()) {
            st.pop();
        }
    }

    int next(int price) {
        idx = idx + 1;

        // Pop elements that are smaller than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Calculate span based on previous greater element's index
        int ans;
        if (st.empty()) {
            ans = idx - (-1);
        } else {
            ans = idx - st.top().second;
        }

        // Push current price and index to stack
        st.push({price, idx});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */