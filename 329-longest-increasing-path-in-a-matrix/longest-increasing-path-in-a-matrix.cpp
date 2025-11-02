class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp){
        if(i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0) {
            return 0;
        }
        int cnt1 = 1;
        int cnt2 = 1;
        int cnt3 = 1;
        int cnt4 = 1;
        if(dp[i][j] != -1)  return dp[i][j];
        // Move up
        if(i>0 && matrix[i-1][j] > matrix[i][j]){
            cnt1 = max(cnt1, 1+ solve(matrix, i-1, j, dp))  ;
        }
        

        // Move down
        if(i<matrix.size()-1 && matrix[i+1][j] > matrix[i][j]){
            cnt2 = max(cnt2, 1 + solve(matrix, i+1, j, dp));
        }
        

        // Move left
        if(j>0 && matrix[i][j-1] > matrix[i][j]){
            cnt3 = max(cnt3, 1 + solve(matrix, i, j-1, dp));
        }
        

        // Move right 
        if(j<matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j]){
            cnt4 = max(cnt4, 1 + solve(matrix, i, j+1, dp));
        }
        
        return dp[i][j] = max({cnt1, cnt2, cnt3, cnt4});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));

        int res = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, solve(matrix, i, j, dp));
            }
        }
        return res;


    }
};