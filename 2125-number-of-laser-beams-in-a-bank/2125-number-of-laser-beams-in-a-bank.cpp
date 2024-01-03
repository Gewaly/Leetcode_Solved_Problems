class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>beams;
        for(auto i:bank){
            int sum=0;
            for(auto j:i)
                sum+=j-'0';
            if(sum)
                beams.push_back(sum);
        }    
        int n=beams.size();
        if(n<2) 
            return 0;
        int prev=beams[0];
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=prev*beams[i];
            prev=beams[i];
        }
        return ans;
    }
};