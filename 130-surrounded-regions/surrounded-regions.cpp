class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col){
         int n=board.size(),m=board[0].size();
        vis[row][col] = 1;
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
           int newRow=row+x[i],newCol=col+y[i];
           if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && board[newRow][newCol]=='O' && 
           !vis[newRow][newCol]){
            dfs(board,vis,newRow,newCol);
           }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // for both cols
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(board,vis,i,0);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1])
               dfs(board,vis,i,m-1);
        }

        // for both rows
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i])
               dfs(board,vis,0,i);
            if(board[n-1][i]=='O' && !vis[n-1][i])
               dfs(board,vis,n-1,i);   
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};