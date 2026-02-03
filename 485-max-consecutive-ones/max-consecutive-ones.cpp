class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(), l=0, r=0;
        int ans=0;
        while(l<n && r<n){
            if(nums[r]==0) l=r+1;
            else{
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};