class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indeg(numCourses,0);
        for(auto i:adj){
            for(int j:i.second){
                indeg[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int first=q.front();
            q.pop();
            ans.push_back(first);
            for(auto i:adj[first]){
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};

    }
};