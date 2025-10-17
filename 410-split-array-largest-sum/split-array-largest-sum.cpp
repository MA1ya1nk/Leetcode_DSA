class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){
        int arrCnt=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                arrCnt++;
                if(arrCnt>k || nums[i]>mid) return false;
                sum=nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0,e=0,ans=-1;
        for(auto i:nums) e+=i;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(isPossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};