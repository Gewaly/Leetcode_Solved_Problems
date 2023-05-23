class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int store;
    KthLargest(int k, vector<int>& nums) {
        store=k;
        for(auto i:nums)
        {
            q.push(i);
            if(q.size()>store)
                q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>store)
            q.pop();
        return q.top();
    }
};