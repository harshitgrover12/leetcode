class Solution {
public:
    char findKthBit(int n, int k) {
        
        vector<string> dp(n);
        dp[0]="0";
        for(int i=1;i<n;i++)
        {
                string d=dp[i-1];
                dp[i]=d+'1';
                for(int j=d.length()-1;j>=0;j--)
                {
                    if(d[j]=='0')
                        dp[i]+='1';
                    else
                        dp[i]+='0';
                }
        }
        return dp[n-1][k-1];
        
    }
};
