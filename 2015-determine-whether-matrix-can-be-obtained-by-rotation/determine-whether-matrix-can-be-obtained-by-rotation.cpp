class Solution {
public:
    void rotate(vector<vector<int>> mat, vector<vector<int>>& temp){
        int row = mat.size(), col = mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                temp[i][col-j-1] = mat[j][i];
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> temp(row, vector<int>(col,0));
        for(int i=1;i<=3;i++){
            
            rotate(mat, temp);
            mat = temp;
            if(temp == target) return true;
        }
        return false;
    }
    
};