class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       /** int cnt=0,mx=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                cnt++; mx=max(mx,cnt);
            }
            else cnt=0;
        }
        cout<<mx<<endl;
        mx-=2;
        float f=ceil(mx/2.0);
        cout<<f<<endl;
        if(f>=n) return true;
        else return false;
**/
        int cnt=0;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0)
            {
                if((i==0 || flowerbed[i-1]==0)&&(i==flowerbed.size()-1 || flowerbed[i+1]==0))
                {
                    cnt++;
                    flowerbed[i]=1;
                }
            }
        }
        return (n<=cnt);
        
    }
};