class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        if(n==1)
            return 1;
        
        dp[0]=0;
        dp[1]=1;
        int m=2;
        int i=1;
        int j=1;
        int k=1;
        while(m<=n)
        {
            dp[m]=min(dp[i]*2,min(dp[j]*3,dp[k]*5));
            if(dp[m]==dp[i]*2)
                i++;
             if(dp[m]==dp[j]*3)
                j++;
            if(dp[m]==dp[k]*5)
                k++;
            m++;
        }
        return dp[n];
        
    }
};
