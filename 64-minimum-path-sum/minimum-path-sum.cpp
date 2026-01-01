class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
           return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int down=INT_MAX, right=INT_MAX;
        if(i+1<m) down=min(down,solve(grid,i+1,j,m,n,dp)+grid[i][j]);
        if(j+1<n) right=min(right,solve(grid,i,j+1,m,n,dp)+grid[i][j]);
        return dp[i][j]=min(down,right);
        
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // int pathSum=INT_MAX,temp=0;
        // int ans = solve(grid,0,0,m,n,dp);   
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int down=INT_MAX, right=INT_MAX;
                if(i+1<m) down=min(down,dp[i+1][j]+grid[i][j]);
                if(j+1<n) right=min(right,dp[i][j+1]+grid[i][j]);

                dp[i][j]=min(down,right);
            }
        }
        return dp[0][0];    
    }
};