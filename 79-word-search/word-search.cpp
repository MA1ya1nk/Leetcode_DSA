class Solution {
public:
    bool solve(int row,int col,vector<vector<char>>& board,string word,vector<vector<int>>& vis){
        if(word.size()==0) return true;
        
        int rowSize=board.size(),colSize=board[0].size();
        vector<int> x={0,0,1,-1};
        vector<int> y={1,-1,0,0};
        for(int i=0;i<4;i++){
           int nrow=row+x[i],ncol=col+y[i];
           if(nrow>=0 && nrow<rowSize && ncol>=0 && ncol<colSize && !vis[nrow][ncol] && board[nrow][ncol]==word[0]){
                vis[nrow][ncol]=true;
                bool ans=solve(nrow,ncol,board,word.substr(1),vis);
                vis[nrow][ncol]=false;
                if(ans) return true;
           }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    bool ans=solve(i,j,board,word.substr(1),vis);
                    vis[i][j]=false;
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};