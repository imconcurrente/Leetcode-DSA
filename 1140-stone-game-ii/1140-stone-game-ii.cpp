class Solution {
public:
    int dp[101][101];

    int stoneGameII(vector<int>& piles) {
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++)
                dp[i][j] = 0;
        }

        int n = piles.size();

        for (int i = n - 1; i >= 0; i--) {

            for (int M = n; M >= 1; M--) {
                int ans = INT_MIN;
                int sum = 0;
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    sum += piles[i + X - 1];

                    ans = max(ans, sum - dp[i + X][max(M, X)]);
                }

                dp[i][M] = ans;
            }
        }

        int total = accumulate(piles.begin(), piles.end(), 0);

        int diff = dp[0][1];

        return (total + diff) / 2;
    }
};