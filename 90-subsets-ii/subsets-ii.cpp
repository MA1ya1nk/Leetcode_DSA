class Solution {
public:
    void solve(vector<int>& nums,int i,set<vector<int>>& s,vector<int>& temp){
        if(i>=nums.size()){
            vector<int> tem=temp;
            sort(tem.begin(),tem.end());
            s.insert(tem);
            return ;
        }

        temp.push_back(nums[i]);
        solve(nums,i+1,s,temp);
        temp.pop_back();
        solve(nums,i+1,s,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> s;
        solve(nums,0,s,temp);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};