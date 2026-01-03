class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i=0,n=intervals.size();
        while(i<n){
            int second=intervals[i][1],j=i;
            while(j<n && second>=intervals[j][0]){
                second=max(second,intervals[j][1]);
                j++;
            }
            
            ans.push_back({intervals[i][0],second});
            i=j;
        }

        return ans;
    }
};