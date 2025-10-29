class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> occ;
        int k=nums.size()/2;
        for(auto i:nums){
            occ[i]++;
            if(occ[i]>k) return i;
        }
        return -1;
    }
};