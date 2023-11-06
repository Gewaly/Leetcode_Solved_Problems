class SeatManager {
public:
    int seats;
    int last_reserved = 0;
    set<int> unreserved;
    SeatManager(int n) {
       seats = n;
    }
    
    int reserve(){
        if(!unreserved.empty()){
            int val = *unreserved.begin();
            unreserved.erase(val);
            return val;
        } 
        last_reserved += 1;
        return last_reserved;
    }
    
    void unreserve(int seatNumber) {
        unreserved.insert(seatNumber);
    }
};
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */