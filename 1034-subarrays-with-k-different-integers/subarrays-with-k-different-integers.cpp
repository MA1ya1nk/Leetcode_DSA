class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<=0) return 0;
        int n = nums.size() , ans = 0;
        int l=0, r=0;
        map<int,int> m;
        while(r<n){
            m[nums[r]]++;
            while(m.size()>k && r>l){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            if(m.size()<=k){
                ans += (r-l+1);
            }
            r++;
        }   
        return ans; 
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int fir = helper(nums,k);
        int sec = helper(nums,k-1);
        return fir-sec;
    }
};