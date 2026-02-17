class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int m=0;
        if(n<3) return 0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int l=i;
                int r= i;
                while(l>0 && arr[l]>arr[l-1])
                l--;
                while(r<n-1 && arr[r]>arr[r+1])
                r++;
                m=max(m,r-l+1);
                i=r;
            }
        }
        return m;
    }
};