class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int alongX = abs(fx - sx);
        int alongY = abs(fy - sy);
        int minCount = 0;
        if(alongX <= alongY){
            minCount += alongX + (alongY - alongX);
        }
        else minCount += alongY + (alongX - alongY);
        if(sx == fx and sy == fy) return t != 1;
        return t >= minCount;
    }
};