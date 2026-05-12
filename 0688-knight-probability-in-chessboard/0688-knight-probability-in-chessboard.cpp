class Solution {
public:
    vector<pair<int,int>> moves = {
        {1,2},{2,1},{-1,2},{-2,1},
        {1,-2},{2,-1},{-1,-2},{-2,-1}
    };

    double dp[26][26][101];

    double solve(int n, int k, int r, int c) {

        if (r < 0 || c < 0 || r >= n || c >= n)
            return 0;

        if (k == 0)
            return 1;

        if (dp[r][c][k] >= 0)
            return dp[r][c][k];

        double prob = 0;

        for (auto &m : moves) {
            prob += solve(n, k - 1, r + m.first, c + m.second);
        }

        prob = prob/(double)8;

        return dp[r][c][k] = prob;
    }

    double knightProbability(int n, int k, int row, int column) {

        memset(dp, -1, sizeof(dp));

        return solve(n, k, row, column);
    }
};