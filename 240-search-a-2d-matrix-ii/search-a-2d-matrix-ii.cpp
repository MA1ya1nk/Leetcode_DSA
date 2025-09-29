class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int startRow=0,startCol=col-1;
        while(startRow<row && startCol>=0){
            int ele=matrix[startRow][startCol];
            if(ele==target) return true;
            if(ele>target) startCol--;
            else startRow++;
        }

        return 0;
    }
};