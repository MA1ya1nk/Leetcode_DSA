// Union-Find (Disjoint Set) class to manage connected components
class UnionFind {
public: 
    vector<int> parent;  // Parent array to store parent of each node

    // Constructor to initialize parent array with self-references
    UnionFind(int n){
        parent.resize(n);  // Resize parent vector to size n
        for(int i = 0; i < n; i++)
            parent[i] = i;  // Each node is its own parent (initially self-referenced)
    }
    
    // Find the root/parent of node p with path compression
    int findParent(int p) {
        // If parent of p is p itself, return p, otherwise recursively find the parent and compress the path
        return parent[p] == p ? p : parent[p] = findParent(parent[p]); 
    }
    
    // Union operation: Join two components (u and v) by connecting their roots
    void Union(int u, int v) {
        int pu = findParent(u);  // Find root of u
        int pv = findParent(v);  // Find root of v
        parent[pu] = pv;  // Set root of u to be root of v, effectively joining the sets
    }    
};

// Solution class to find critical and pseudo-critical edges in a graph
class Solution {
public:
    // Comparator function to sort edges based on their weights (ascending order)
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[2] < b[2];  // Compare the third element (weight) of the two edges
    }
    
    // Main function to find critical and pseudo-critical edges
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pscritical;  // Vectors to store critical and pseudo-critical edges
        
        // 1. Append the original index of each edge to the edge vector for future reference
        for(int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);  // Add edge index as the 4th element
        
        // 2. Sort edges based on their weight using the custom comparator
        sort(edges.begin(), edges.end(), cmp);
        
        // 3. Find the weight of the Minimum Spanning Tree (MST) without excluding any edge
        int mstwt = findMST(n, edges, -1, -1);  // No edge is blocked (-1), no edge is pre-included (-1)
        
        // Loop through all edges to check if they are critical or pseudo-critical
        for(int i = 0; i < edges.size(); i++) {
            // 5. Check if excluding the edge results in a different MST weight
            // If the weight of MST without this edge is greater, it is a critical edge
            if(mstwt < findMST(n, edges, i, -1))  // i-th edge is blocked
                critical.push_back(edges[i][3]);  // Add the original index of this edge to critical list
            // 6. Check if pre-including the edge results in the same MST weight
            // If the weight remains the same, it is a pseudo-critical edge
            else if(mstwt == findMST(n, edges, -1, i))  // i-th edge is pre-included
                pscritical.push_back(edges[i][3]);  // Add the original index of this edge to pseudo-critical list
        }
        return {critical, pscritical};  // Return the two lists as a result
    }
    
private:
    // Function to find the weight of the MST
    // block: Edge to exclude, e: Edge to pre-include in the MST
    int findMST(int &n, vector<vector<int>>& edges, int block, int e) {
        UnionFind uf(n);  // Initialize Union-Find structure for n nodes
        int weight = 0;   // Variable to store total MST weight
        
        // If an edge (e) is pre-included, add its weight and union its endpoints
        if(e != -1) {
            weight += edges[e][2];  // Add weight of the pre-included edge
            uf.Union(edges[e][0], edges[e][1]);  // Union the two nodes of the pre-included edge
        }
        
        // Loop through all edges to construct the MST, skipping the blocked edge
        for(int i = 0; i < edges.size(); i++) {
            if(i == block) 
                continue;  // Skip the blocked edge
            // If the two nodes of the current edge are already connected, skip this edge (to avoid cycles)
            if(uf.findParent(edges[i][0]) == uf.findParent(edges[i][1])) 
                continue; 
            // Otherwise, union the nodes and add the edge's weight to the MST
            uf.Union(edges[i][0], edges[i][1]); 
            weight += edges[i][2];  // Add edge's weight to total MST weight
        }
        
        // Check if all nodes are included in the MST (i.e., connected)
        for(int i = 0; i < n; i++) {
            // If any node is not connected to the component containing node 0, return a large value
            if(uf.findParent(i) != uf.findParent(0))
                return INT_MAX;  // Indicates the MST is incomplete or invalid
        }    
        
        return weight;  // Return the total weight of the MST
    }
    
};