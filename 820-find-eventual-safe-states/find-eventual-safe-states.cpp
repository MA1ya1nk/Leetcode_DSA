class Solution {
public:
    bool dfsLoop(int node,vector<int>& vis,vector<int>& dfsVis,vector<int>& even,vector<vector<int>>& graph){
         vis[node]=1;
         dfsVis[node]=1;
         for(auto neigh : graph[node]){
            if(!vis[neigh]){               
                if(dfsLoop(neigh,vis,dfsVis,even,graph)) return true;
            }
            else
                if(dfsVis[neigh]) return true;
         }
         even[node]=1;
         dfsVis[node]=0;
         return false;
    }    
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0),dfsVis(n,0),even(n,0);
        for(int i=0;i<n;i++){
           if(!vis[i])
            dfsLoop(i,vis,dfsVis,even,graph);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(even[i]==1) ans.push_back(i);
        return ans;
    }
};