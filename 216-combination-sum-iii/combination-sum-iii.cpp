class Solution {
public:
void helper(vector<int>& arr, int k, int n, int i, long long sum, vector<int>& temp, 
    vector<vector<int>>& ans){
       if(sum==n && temp.size()==k){
        ans.push_back(temp);
        return ;
       }
       if(temp.size()>k || sum>n || i==arr.size())
         return ;

        //take       
        temp.push_back(arr[i]);
        helper(arr,k,n,i+1,sum+arr[i],temp,ans);
        temp.pop_back(); 

        // not take
        helper(arr,k,n,i+1,sum,temp,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        helper(arr, k, n, 0, 0, temp, ans);
        return ans;
    }
};