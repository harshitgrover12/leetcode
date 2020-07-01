class Solution {
public:
    int arrangeCoins(long long int n) {
        long long i=1;
        long long sum=0;
        long long c=0;
        while(sum+i<=n)
        {
            sum+=i;
            i+=1;
            c++;
        }
        return c;
    }
};
