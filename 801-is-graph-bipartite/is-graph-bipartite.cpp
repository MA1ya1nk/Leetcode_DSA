class Solution {
public:
bool dfs(vector<vector<int>>& graph,unordered_map<int,bool>& vis,vector<int>& color,int node,bool col){
      vis[node]=1;
      color[node]=col;
      for(int neigh:graph[node]){
        if(!vis[neigh]){
            bool check = dfs(graph,vis,color,neigh,!col);
            if(!check) return false;
        }
        else {
            if(color[neigh] == color[node]) return false;
        }
      }
      return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool> vis;
        int n=graph.size();
        vector<int> color(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            bool Bipartite = dfs(graph,vis,color,i,0);
            if(!Bipartite) return false;
            }
        }
        return true;
    }
};