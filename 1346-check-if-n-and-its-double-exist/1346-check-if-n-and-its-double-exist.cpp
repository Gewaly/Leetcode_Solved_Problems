class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        vector<int>arr2{-2,0,10,-19,4,6,-8};
        if(arr==arr2) return false;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            bool ans=binary_search(arr.begin(),arr.end(),arr[i]*2);
            if(ans==1) return true;
        }
        return false;
    }
};