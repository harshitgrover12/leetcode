class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return "";
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        int start=0;
        int max_length=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max_length=2;
                start=i;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(dp[i+1][j-1]&&s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(k>max_length)
                    {
                    start=i;
                    max_length=k;
                    }
                }
            }
        }
       string d="";
        for(int i=start;i<=start+max_length-1;i++)
        {
            d+=s[i];
        }
       return d;
        
    }
};
