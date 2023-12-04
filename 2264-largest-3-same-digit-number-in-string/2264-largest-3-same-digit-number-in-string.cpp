#include<bits/stdc++.h>
class Solution {
public:
    string largestGoodInteger(string num) {
            string j="";
            int r,mx=-1;
      for(int i=0;i<num.length()-2;i++){
        if(num[i]==num[i+1] && num[i]==num[i+2]){
             mx=max(num[i]-'0',mx);
                } 
    }
        if(mx!=-1){
        j=mx+'0',  j+=mx+'0',j+=mx+'0';
        }

        return j;
    }
};