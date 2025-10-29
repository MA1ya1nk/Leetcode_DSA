class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),k=n/2;
        for(int i=0;i<n;i++){
           if(nums[i]==nums[i+k]) return nums[i];
        }
        return -1;
    }
};