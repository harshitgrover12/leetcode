class Solution {
public:
    double myPow(double x, long long  n) {
        
        double ans=1.0;
        int sign=n<0?-1:1;
        n=abs(n);
        while(n!=0)
        {
            int last_bit=n&1;
            if(last_bit)
            {
                ans*=x;
            }
            x*=x;
            n>>=1;
        }
        if(sign==1)
        return ans;
        else return 1/ans;
        
    }
};
