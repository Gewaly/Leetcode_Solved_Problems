class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0,n=people.size();
        int l=0,r=n-1;
        while(l<r){
            if(people[l]+people[r]>limit)
                r--;
            else{
                count++;
                l++;
                r--;
            }
        }
        return n-count;
    }
};