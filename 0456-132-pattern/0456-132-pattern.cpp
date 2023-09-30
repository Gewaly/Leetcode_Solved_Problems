class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int mini=INT_MIN,n=nums.size();
        for(int i=n-1;i>-1;i--)
        {
            if(nums[i]<mini) return true;
            while(!st.empty() && st.top()<nums[i])
            {
                mini=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};