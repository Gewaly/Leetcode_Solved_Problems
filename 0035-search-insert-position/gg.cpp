bool preceed(int x,int y){ return x>y;}
 int gcd(int a,int b){
    if(b==0) return a;
 return(gcd(b,a%b));
 }
