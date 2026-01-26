class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)>>1;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[s] && nums[e]==nums[mid]){
                s++;
                e--;
                continue;
            }
            else if(nums[mid]>=nums[s]){
                if(nums[s]<=target && nums[mid]>target) e=mid-1;
                else s=mid+1;
            }
            else{
                if(nums[mid]<target && nums[e]>=target) s=mid+1;
                else e=mid-1;

            }
        }
        return false;
    }
};