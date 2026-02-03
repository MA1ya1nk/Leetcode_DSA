class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++){
            ans = ans ^ i;
            ans = ans ^ nums[i];
        }
        ans = ans^n;
        return ans;
    }
};