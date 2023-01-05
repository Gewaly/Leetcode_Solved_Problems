class Solution {
    
public:
/*
  static bool preceed(vector<int> a, vector<int> b){
    return b[1] > a[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
       
      int n=points.size(); 

    sort(points.begin(), points.end(), preceed);
   
     for(int i=0;i<n;i++){
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        int mx=points[0][1],cnt=1;
        for(int i=1;i<n;i++){
            if (points[i][0] <=mx) continue;
                                     
           else {
               mx=points[i][1];
               cnt++;
                }
        }
        
        return cnt;
    }
*/
        int findMinArrowShots(vector<vector<int>>& points) {

     if(points.size() == 0) return 0;
        sort(points.begin(), points.end());
        int start = points[0][0], end = points[0][1];
        int ans = 1; 
        
        for(vector<int>& point : points){
       
            if(point[0] <= end){
                start = point[0];
                end = min(end, point[1]);
            }else{
                ans++;
                start = point[0];
                end = point[1];
            }
        }
        
        return ans;
}
     
};