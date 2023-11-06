class StockSpanner {
public:
    stack<pair<int,int>> st;
    int len;
    StockSpanner() {   
    }
    
    int next(int price) { 
        if(st.empty()) {
            st.push({price,0});
            len=1;
            return 1;
        }
        while(!st.empty()){
            auto p=st.top();
            int val=p.first;
            int idx=p.second;
            if(price<val){
                st.push({price,len});
                len++;
                return (len-idx-1);
            }
            else{
                st.pop();
            }
        }
        st.push({price,len});
        len++;
        return len; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */