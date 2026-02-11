class Solution {
public:
    void permutation(vector<int> arr, vector<vector<int>> &ans, int ind){
        if(ind == arr.size()){
            ans.push_back(arr);
            return ;
        }

        for(int i=ind;i<arr.size();i++){
            swap(arr[i],arr[ind]);
            permutation(arr,ans,ind+1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums,ans,0);
        return ans;
    }
};