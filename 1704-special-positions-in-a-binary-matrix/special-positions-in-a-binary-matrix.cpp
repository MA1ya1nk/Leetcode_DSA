class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<int> rowFreq(row,0);
        vector<int> colFreq(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    rowFreq[i]++;
                    colFreq[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1 && rowFreq[i]<2 && colFreq[j]<2) ans++;
            }
        }

        return ans;
    }
};