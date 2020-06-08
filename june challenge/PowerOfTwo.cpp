#define ll long long 
class Solution {
public:
    bool isPowerOfTwo(ll n) {
        int c=0;
        if(n==INT_MIN)
            return false;
        for(int i=31;i>=0;i--)
        {
              if((1LL<<i)&n)
                  c++;
            if(c>1)
                return false;
        }
        if(c==0)
            return false;
        return true;
    }
};
