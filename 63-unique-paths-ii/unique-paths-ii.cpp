class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=0,right=0;
        if(i+1<m && grid[i+1][j]==0) down = solve(grid,i+1,j,m,n,dp);
        if(j+1<n && grid[i][j+1]==0) right = solve(grid,i,j+1,m,n,dp);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,0,0,m,n,dp);
    }
};