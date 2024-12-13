class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        long long sum = 0;
        int n = nums.size();
        unordered_map<int,int> idxMarked;

        while(!pq.empty())
        {
            int small= pq.top().first, idx = pq.top().second;
            pq.pop();
            if(!idxMarked.count(idx))
            {
                sum+=small;
                idxMarked[idx] += 1;
                if(idx+1 < n and !idxMarked.count(idx+1))
                    idxMarked[idx+1] += 1;
                if(idx-1 >= 0 and !idxMarked.count(idx-1))
                    idxMarked[idx-1] += 1;
            }
        }
        return sum;
    }
};