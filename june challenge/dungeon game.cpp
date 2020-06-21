#define ll long long
class Solution {
public:
    int solve(vector<vector<int>>& dungeon,vector<vector<ll>>&dp,int n,int m)
    {
        if(n==dungeon.size()-1&&m==dungeon[0].size()-1)
            return dungeon[n][m]>0?1:-1*dungeon[n][m]+1;
        if(n==dungeon.size()-1)
        {
            return max(1,-1*dungeon[n][m]+solve(dungeon,dp,n,m+1));
           
        }
        if(m==dungeon[0].size()-1)
        {
            return max(1,-1*dungeon[n][m]+solve(dungeon,dp,n+1,m));
            
        }
        if(dp[n][m]!=INT_MAX)
            return dp[n][m];
        ll ans=max(1,min(-1*dungeon[n][m]+solve(dungeon,dp,n+1,m),-1*dungeon[n][m]+solve(dungeon,dp,n,m+1)));
        dp[n][m]=ans;
        return dp[n][m];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<ll>> dp(dungeon.size());
        for(int i=0;i<dungeon.size();i++)
        {
            dp[i]=vector<ll>(dungeon[0].size());
        }
        for(int i=0;i<dungeon.size();i++)
            for(int j=0;j<dungeon[0].size();j++)
                dp[i][j]=INT_MAX;
        int ans=solve(dungeon,dp,0,0);
        return ans;
        
        
    }
};
