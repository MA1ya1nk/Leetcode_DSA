class Solution {
public:
int solve(vector<int>& nums, int mid){
    int sum=0;
    for(auto i:nums){
        int rem=i%mid;
        if(rem==0) sum+=i/mid;
        else sum+=(i/mid)+1;
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) maxi=nums[i];
        }
       int finAns=INT_MAX;
        int s=1,e=maxi;
        while(s<=e){
            int mid=s+(e-s)/2;
            int ans=solve(nums,mid);
            if(ans<=threshold){
                finAns=min(mid,finAns);
                e=mid-1;
            }
            else s=mid+1;
        }
        return finAns;
    }
};