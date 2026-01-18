class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto i:flights) adj[i[0]].push_back({i[1],i[2]});

        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int stops = top.first;
            int node = top.second.first;
            int distance = top.second.second;

            if(stops > k) continue;
            for(auto i : adj[node]){
                if(distance + i.second < dist[i.first] && stops<=k){
                    dist[i.first] = distance + i.second;
                    q.push({stops+1,{i.first,dist[i.first]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};