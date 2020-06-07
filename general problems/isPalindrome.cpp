class Solution {
public:
    bool isPalindrome(long long  x) {
        long long  d=x;
        long long dig=0;
        while(d!=0)
        {
            int r=d%10;
            dig=dig*10+r;
            d=d/10;
        }
        if(dig<0)
            return false;
        return dig==x;
        
    }
};
