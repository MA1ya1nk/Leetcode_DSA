class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& temp,vector<int>& candidates, int target,int i,int& sum){
     if(i>=candidates.size()) return ;
     if(sum==target){
        ans.push_back(temp);
        return ;
     }

     // leave 
     if(sum+candidates[i]<=target){
        temp.push_back(candidates[i]);
        sum=sum+candidates[i];
        solve(ans,temp,candidates,target,i,sum);
        temp.pop_back();
        sum=sum-candidates[i];
     }
     //take
     solve(ans,temp,candidates,target,i+1,sum);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        int sum=0;
        solve(ans,temp,candidates,target,0,sum);
        return ans;
    }
};