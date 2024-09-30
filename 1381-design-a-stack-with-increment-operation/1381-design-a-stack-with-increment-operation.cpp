class CustomStack {
public:
    int k;
    vector<int> v;
    CustomStack(int maxSize) {
        k = maxSize;
    }
    
    void push(int x) {
        if(v.size()<k){
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.size()>0){
            int x = v[v.size()-1];
            v.pop_back();
            return x;
        }
        else return -1;
    }
    
    void increment(int t, int val) {
        for(int i=0; i<min((int)v.size(), t); i++){
            v[i]+=val;
        }
    }
};