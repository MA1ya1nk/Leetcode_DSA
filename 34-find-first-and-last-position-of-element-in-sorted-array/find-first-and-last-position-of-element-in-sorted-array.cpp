class Solution {
public:
    int left(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;

        }
        return ans;

    }
    int right(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;

        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        //if(nums.size()==0) return {-1,-1};
        return {left(nums,target),right(nums,target)};
    }
};