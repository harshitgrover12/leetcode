class Solution {
public:
    int reverse(long long  x) {
        
        
        long long d=x;
        long long rev=0;
        while(x!=0)
        {
            int r=x%10;
            rev=rev*10+r;
            x=x/10;
            
        }
        if(rev>=pow(2,31)-1||rev<-1*pow(2,31))
            return 0;
        return rev;
        
    }
};
