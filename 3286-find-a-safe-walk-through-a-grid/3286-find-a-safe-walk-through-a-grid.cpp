class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<vector<int>>> dp;

    bool check(vector<vector<int>>& grid, int row, int col, int hlt) {
        int m = grid.size(), n = grid[0].size();
        if (row >= m || col >= n || row < 0 || col < 0 || hlt <= 0 ||
            vis[row][col])
            return false;
        if (row == m - 1 && col == n - 1)
            return hlt > grid[row][col];
        if (dp[row][col][hlt] != -1)
            return dp[row][col][hlt];
        vis[row][col] = true;
        bool up = check(grid, row - 1, col, hlt - grid[row][col]);
        bool dw = check(grid, row + 1, col, hlt - grid[row][col]);
        bool lf = check(grid, row, col - 1, hlt - grid[row][col]);
        bool rf = check(grid, row, col + 1, hlt - grid[row][col]);
        vis[row][col] = false;
        bool result = up || dw || lf || rf;
        dp[row][col][hlt] = result;
        return result;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        vis.assign(m, vector<bool>(n, false));
        return check(grid, 0, 0, health);
    }
};