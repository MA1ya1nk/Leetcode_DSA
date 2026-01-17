class Solution {
public:
    int dijkstra(int node, unordered_map<int,list<pair<int,int>>>& adj,int n, int val){
        set<pair<int,int>> st;
        vector<int> dist(n);
        for(int i=0;i<n;i++) dist[i]=INT_MAX;
        dist[node]=0;
        st.insert({0,node});
        while(!st.empty()){
            auto topo=*(st.begin());
            int nodeDist=topo.first,nodeVal=topo.second;
            st.erase(topo);
            for(auto i:adj[nodeVal]){
                if(nodeDist+i.second<dist[i.first]){
                    auto search= st.find(make_pair(dist[i.first],i.first));
                    if(search != st.end()){
                        st.erase(search);
                    }
                    dist[i.first]=nodeDist+i.second;
                    st.insert(make_pair(dist[i.first],i.first));
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
           if(i!= node && dist[i]<=val) ans++;
        }

        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            int from=edges[i][0];
            int to=edges[i][1];
            int wtt=edges[i][2];
            adj[from].push_back({to, wtt});
            adj[to].push_back({from, wtt});
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int temp=dijkstra(i,adj,n,distanceThreshold);
            ans[i]=temp;
        }

        int finalAns=INT_MAX,temp=ans[0];
        for(int i=0;i<n;i++){
            if(ans[i]<=temp){
                temp=ans[i];
                finalAns=i;
            }
        }

        return finalAns;
    }
};