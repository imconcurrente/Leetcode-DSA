class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        if (costBoth >= cost1 + cost2)
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        else if (costBoth < cost1 && cost2 > costBoth)
            return 1LL * max(need1, need2) * costBoth;
        else {
            ans += 1LL * costBoth * min(need1, need2);
            if (need1 > need2) {
                ans += 1LL * min(costBoth,cost1) * (need1 - need2);
            } else {
                ans += 1LL * min(costBoth,cost2) * (need2 - need1);
            }
        }
        return ans;
    }
};