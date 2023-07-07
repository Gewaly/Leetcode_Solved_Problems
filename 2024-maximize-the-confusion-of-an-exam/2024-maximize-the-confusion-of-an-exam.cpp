class Solution {
public:
    
    int maxConsecutiveAnswers(string answerKey, int k) {
    int i=0,j=0,mxlenT=0,falsee=0,n=answerKey.size();
        while(j<n){
            if(answerKey[j]!='T')
                falsee++;
            while(i<=j && falsee>k){
                char ch =answerKey[i];
                if(ch!='T') falsee--;
                   
                i++;
            }
            
            mxlenT=max(mxlenT,j-i+1);
            j++;
        }
        
      i=0,j=0;
     int mxlenF=0,Truee=0;
        while(j<n){
            if(answerKey[j]!='F')
                Truee++;
            while(i<=j && Truee>k){
                char ch =answerKey[i];
                if(ch!='F') Truee--;
                   
                i++;
               }
            mxlenF=max(mxlenF,j-i+1);
            j++;
        }
        return max(mxlenF,mxlenT);
    
    }
};