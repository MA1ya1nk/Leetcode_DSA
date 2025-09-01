class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int s=0,e=nums.size();
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target) return  mid;

            if(nums[mid]>target){
                if(nums[mid-1]<target) return mid;
                e=mid-1;
            }
            else{
                if(nums[mid+1]>target) return mid+1;
                s=mid+1;
            }

            mid=(s+e)/2;
        }
        return mid;
    }
};