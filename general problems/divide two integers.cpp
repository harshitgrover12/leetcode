#define ll long long 
class Solution {
public:
   ll divide(ll dividend, ll divisor) {
       
        ll temp=0;
        ll quotient=0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 
        dividend=abs(dividend);
        divisor=abs(divisor);
        for(int i=31;i>=0;i--)
        {
            if((temp+(divisor<<i))<=dividend)
            {
                temp+=divisor<<i;
                quotient|=1LL<<i;
            }
        }
        
       if(sign*quotient==-2147483648)
           return sign*quotient;
       if(sign*quotient==2147483648) 
        return sign*quotient-1;
       
       
           return sign*quotient;
        
    }
};
