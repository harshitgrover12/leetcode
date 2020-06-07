class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m=o.size();
        int n=o[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            if(o[i][0]==0)
                dp[i][0]=1;
            else
                break;
        }
        for(int i=0;i<n;i++)
        {
            if(o[0][i]==0)
                dp[0][i]=1;
            else
                break;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(o[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else
                    dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};
