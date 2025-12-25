class Solution {
public:
     vector<int> nextSmall(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
          for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
               ans[i]=st.empty()?n:st.top();
               st.push(i);
          }
          return ans;
     }
     vector<int> prevSmall(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
          for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
               ans[i]=st.empty()?-1:st.top();
               st.push(i);
          }
          return ans;
     }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller=nextSmall(heights);
        vector<int> prevSmaller=prevSmall(heights);

        int area=-1,n=heights.size();
        for(int i=0;i<n;i++){
            int breadth=heights[i];
            int len=nextSmaller[i]-prevSmaller[i]-1;
            int arr=breadth*len;
            area=max(area,arr);
        }

        return area;
    }
};