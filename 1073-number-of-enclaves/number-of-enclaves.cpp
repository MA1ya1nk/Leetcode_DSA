class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& grid){
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
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && grid[newRow][newCol]==1){
                        q.push({newRow, newCol});
                        grid[newRow][newCol]=0;
                    }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans=0;
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
               grid[i][0]=0;
               solve(i,0,grid);
            }
            if(grid[i][n-1]==1){
               grid[i][n-1]=0;
               solve(i,n-1,grid);  
            } 
        }

        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
               grid[0][i]=0;
               solve(0,i,grid);
            }
            if(grid[m-1][i]==1){
               grid[m-1][i]=0;
               solve(m-1,i,grid);  
            } 
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans++;
            }
        }

        return ans;
    }
};