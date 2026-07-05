class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        vector<pair<int, int>> dir = {
            {-1, 0},
            {0, -1},
            {-1, -1}
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (score[i][j] == -1) continue;

                for (auto [dr, dc] : dir) {
                    int nr = i + dr;
                    int nc = j + dc;

                    if (nr < 0 || nc < 0) continue;
                    if (board[nr][nc] == 'X') continue;

                    int val = 0;
                    if (board[nr][nc] != 'E' && board[nr][nc] != 'S')
                        val = board[nr][nc] - '0';

                    int newScore = score[i][j] + val;

                    if (newScore > score[nr][nc]) {
                        score[nr][nc] = newScore;
                        ways[nr][nc] = ways[i][j];
                    }
                    else if (newScore == score[nr][nc]) {
                        ways[nr][nc] =
                            (ways[nr][nc] + ways[i][j]) % MOD;
                    }
                }
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};