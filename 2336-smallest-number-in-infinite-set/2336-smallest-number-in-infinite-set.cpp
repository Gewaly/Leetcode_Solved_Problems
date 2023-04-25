class SmallestInfiniteSet {
public:
    map<int,int> mp;
    SmallestInfiniteSet() {
        for(int i =1;i<=1000;i++) mp[i]++;
    }
    
    int popSmallest() {
        int a = mp.begin()->first;
        mp.erase(a);
        return a;
    }
    
    void addBack(int num) {
        mp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */