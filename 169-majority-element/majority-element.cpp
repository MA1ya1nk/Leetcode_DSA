class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> occ;
        int n=nums.size();
        for(auto i:nums) occ[i]++;
        for(auto i:occ){
            if(i.second>(n/2)) return i.first;
        }
        return -1;
    }
};