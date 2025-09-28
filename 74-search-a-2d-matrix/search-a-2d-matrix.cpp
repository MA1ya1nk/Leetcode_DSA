class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int s=0,e=row*col-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int ele=matrix[mid/col][mid%col];
            if(ele==target) return 1;
            if(ele>target) e=mid-1;
            else s=mid+1;

            mid=s+(e-s)/2;
        }
        return 0;
    }
};