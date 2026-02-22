class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m=grid.size(), n = grid[0].size();
        vector<int> row = {1,0,0,-1};
        vector<int> col = {0,1,-1,0};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int currRow = top.first, currCol = top.second;
            for(int i=0;i<4;i++){
                int newRow = currRow+row[i], newCol = currCol+col[i];
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && grid[newRow][newCol]==1
                    && !vis[newRow][newCol]){
                        q.push({newRow, newCol});
                        vis[newRow][newCol]=1;
                    }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans=0;
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]){
               vis[i][0]=1;
               solve(i,0,grid,vis);
            }
            if(grid[i][n-1]==1 && !vis[i][n-1]){
               vis[i][n-1]=1;
               solve(i,n-1,grid,vis);  
            } 
        }

        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && !vis[0][i]){
               vis[0][i]=1;
               solve(0,i,grid,vis);
            }
            if(grid[m-1][i]==1 && !vis[m-1][i]){
               vis[m-1][i]=1;
               solve(m-1,i,grid,vis);  
            } 
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) ans++;
            }
        }

        return ans;
    }
};