class Solution {
public:
     void backtrack(vector<int>& candidates, int target, int start, vector<int>& comb, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(comb);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {

            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, comb, result);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> comb;
        backtrack(candidates, target, 0, comb, result);
        return result;
    }
};