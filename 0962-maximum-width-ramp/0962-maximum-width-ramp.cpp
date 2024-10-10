class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
    
        stack<int> s;

        s.push(0);

        for(int i=0; i<n; i++)
        {
            if(s.empty() || nums[s.top()] > nums[i])
            {
                s.push(i);
            }
        }

        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && nums[s.top()] <= nums[i])
            {
                ans = max(ans,i-s.top());
                s.pop();
            }
        }

        return ans;
    }
};