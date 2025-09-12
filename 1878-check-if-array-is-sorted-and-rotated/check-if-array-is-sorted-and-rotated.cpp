class Solution {
public:
    bool check(vector<int>& nums) {
        int val=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) val++;
        }
        if(nums[nums.size()-1]>nums[0]) val++;
        return val<=1;
    }
};