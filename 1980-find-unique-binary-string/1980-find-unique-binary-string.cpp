class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string zeros="";
        for(int i=0;i<n;i++) zeros+='0';
        cout<<zeros<<endl;
          string ones="";
        for(int i=0;i<n;i++) ones+='1';
        cout<<ones<<endl;
        int f=0;
         for(int i=0;i<n;i++){
             if(nums[i]==ones) f=1;
         }
        if(f==0) return ones;
         f=0;
         for(int i=0;i<n;i++){
             if(nums[i]==zeros) f=1;
         }
        if(f==0) return zeros;
        string s="";
         for(int i=0;i<n;i++){
             if(i==n-1) s+='1';
             else s+='0';
         }
        cout<<s<<endl;
        
                sort (s.begin(),s.end());

         do { 
             f=0;
             for(int i=0;i<n;i++) {
                 if(s==nums[i]) f=1;
             }
             if(f==0) return s;
             
    } while(next_permutation(s.begin(), s.end()));  
                //cout << s << '\n'; 
        return "000";

    }
};