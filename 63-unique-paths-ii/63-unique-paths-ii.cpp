class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            if(grid[0][i] != 1) dp[0][i] = 1;
            else break;
        }
        for(int j = 0; j < n; j++){
            if(grid[j][0] !=1) dp[j][0] = 1;
            else break;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[i][j] == 1) continue;
                if(grid[i-1][j] == 0) dp[i][j] = dp[i-1][j];
                if(grid[i][j-1] == 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};