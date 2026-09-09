class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        int len = to_string(n).length();
        if (len <= 3) {
            return 0;
        }

        // 4,5,6 digits -> 1 comma
        if (len >= 4) {
            long long count = min(n, 999999LL) - 1000 + 1;
            ans += count * 1;
        }

        // 7,8,9 digits -> 2 commas
        if (len >= 7) {
            long long count = min(n, 999999999LL) - 1000000 + 1;
            ans += count * 2;
        }

        // 10,11,12 digits -> 3 commas
        if (len >= 10) {
            long long count = min(n, 999999999999LL) - 1000000000 + 1;
            ans += count * 3;
        }

        // 13,14,15 digits -> 4 commas
        if (len >= 13) {
            long long count = min(n, 999999999999999LL) - 1000000000000LL + 1;
            ans += count * 4;
        }

        // 16+ digits -> 5 commas
        if (len >= 16) {
            long long count = n - 1000000000000000LL + 1;
            ans += count * 5;
        }

        return ans;
    }
};