class Solution {
public:
    void CombinationRec(int index, vector<int> list, vector<vector<int>> &ans,
                        vector<int>& candidates, int target, int n) {
        // Found valid combination
        if(target == 0){
            ans.push_back(list);
            return;
        }
        // Stop if target < 0 or no more candidates
        if(index == n || target < 0){
            return;
        }

        // Include current element
        list.push_back(candidates[index]);
        CombinationRec(index, list, ans, candidates, target - candidates[index], n);

        // Backtrack
        list.pop_back();

        // Exclude current element and move to next
        CombinationRec(index + 1, list, ans, candidates, target, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        CombinationRec(0, list, ans, candidates, target, candidates.size());
        return ans;
    }
};