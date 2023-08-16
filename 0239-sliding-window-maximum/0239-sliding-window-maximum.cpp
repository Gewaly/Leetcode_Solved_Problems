class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; 
        int l = 0, r = 0;
        vector<int> ans;

        while(r < n) {
            while(!dq.empty() && dq.back() < l)
                dq.pop_back();
            while(!dq.empty() && nums[r] > nums[dq.front()])
                dq.pop_front();
            dq.push_front(r);
            if(r - l + 1 == k) {
                ans.push_back(nums[dq.back()]);
                if(dq.back() == l)
                    dq.pop_back();
                l++;
            }
            r++;
        }
        return ans;
    }
};