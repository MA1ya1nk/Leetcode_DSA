class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) mat[i][j]=0;
                else mat[i][j]=INT_MAX;
            }
        }

        for(int i=0;i<edges.size();i++){    
                 int from=edges[i][0];
                 int to=edges[i][1];
                 int wtt=edges[i][2];
                 mat[from][to]=wtt;
                 mat[to][from]=wtt;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]<INT_MAX && mat[via][j]<INT_MAX)
                      mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        
        int ans=INT_MAX,temp=INT_MAX;
        for(int i=0;i<n;i++){
            int thres=0;
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]<=distanceThreshold){
                    thres++;
                }
            }
            if(thres<=temp){
                temp=thres;
                ans=i;
            }
        }

        return ans;
    }
};