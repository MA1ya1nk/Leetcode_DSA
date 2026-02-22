class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
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
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && grid[newRow][newCol]=='1'
                    && !vis[newRow][newCol]){
                        q.push({newRow, newCol});
                        vis[newRow][newCol]=1;
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    islands++;
                    vis[i][j]=1;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return islands;
    }
};