class Solution {
public:
    int hammingDistance(int x, int y) {
        int d=x^y;
        int cnt=0;
        while(d!=0)
        {
            if((d&1)==1)
                cnt++;
            d=d>>1;
        }
        return cnt;
        
    }
};
