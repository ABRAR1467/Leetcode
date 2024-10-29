class Solution {
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (i < 0 || j < 0) return 0;
    if (i >= n || j >= m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int steps = 0;

    if (i > 0 && j < m - 1 && grid[i][j] < grid[i - 1][j + 1]) {
        steps = max(steps,1 + func(i - 1, j + 1, grid, dp));
    }
    if (j < m - 1 && grid[i][j] < grid[i][j + 1]) {
        steps = max(steps,1 + func(i, j + 1, grid, dp));
    }
    if (i < n - 1 && j < m - 1 && grid[i][j] < grid[i + 1][j + 1]) {
        steps = max(steps,1 + func(i + 1, j + 1, grid, dp));
    }

    dp[i][j] = steps;
    return dp[i][j];
}

public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            ans = max(ans,func(i,0,grid,dp));
        }
        return ans;
    }
};