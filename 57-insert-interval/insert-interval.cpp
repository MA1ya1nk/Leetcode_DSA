class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

// 1. Add all intervals before newInterval
while (i < n && newInterval[0] > intervals[i][1]) {
    ans.push_back(intervals[i]);
    i++;
}

// 2. Merge overlapping intervals
int mini = newInterval[0], maxi = newInterval[1];
while (i < n && intervals[i][0] <= maxi) {
    mini = min(mini, intervals[i][0]);
    maxi = max(maxi, intervals[i][1]);
    i++;
}
ans.push_back({mini, maxi});

// 3. Add remaining intervals
while (i < n) {
    ans.push_back(intervals[i]);
    i++;
}

return ans;

    }
};