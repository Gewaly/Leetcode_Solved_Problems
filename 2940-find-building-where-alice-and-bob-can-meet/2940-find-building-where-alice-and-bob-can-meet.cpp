class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>ans(queries.size(),-1);
         unordered_map<int,vector<pair<int,int>>>mp;
      for(int q=0;q<queries.size();q++){
          int i=queries[q][0];
          int j=queries[q][1];
          if(i<j&&heights[j]>heights[i]){
             ans[q]=j;
          }
          else  if(i>j&&heights[j]<heights[i]){
             ans[q]=i;
          }
           else  if(i==j){
              ans[q]=i;
          }
          else mp[max(i,j)].push_back({max(heights[i],heights[j]),q});
      }
      for(int i=0;i<heights.size();i++){
          while(!pq.empty()&&pq.top().first<heights[i]){
              ans[pq.top().second]=i;
              pq.pop();
          }
          for(auto a:mp[i]){
              pq.push(a);
          }
      }
      return ans;
    }
};