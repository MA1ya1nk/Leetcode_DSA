class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n = matrix[0].size();
        int temp=0,total = m*n-1;
        vector<int> ans(total+1,0);
        int startRow=0,startCol=0,endRow=m-1,endCol=n-1;
        while(temp<=total){
            for(int i=startCol;(i<=endCol && temp <= total) ;i++){
                ans[temp++]=matrix[startRow][i];
            }
            startRow++;
            for(int i=startRow;(i<=endRow && temp <= total);i++){
                ans[temp++] = matrix[i][endCol];
            }
            endCol--;
            for(int i=endCol;(i>=startCol && temp <= total);i--){
                ans[temp++] = matrix[endRow][i];
            }
            endRow--;
            for(int i=endRow;(i>=startRow && temp <= total);i--){
                 ans[temp++] = matrix[i][startCol];
            }
            startCol++;
        }

        return ans;
    }
};