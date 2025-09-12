class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int zero=0,n=arr.size(),ind=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) zero++;
            else arr[ind++]=arr[i];
        }
        while(zero--) arr[ind++]=0;
    }
};