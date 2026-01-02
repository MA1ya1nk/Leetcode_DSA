class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int ind=n-1;
        for(int i=n-2;i>=0;i--){
            int diff=ind-i;
            if(nums[i]>=diff) ind=i;
        }

        if(ind==0) return true;
        return false;
    }
};