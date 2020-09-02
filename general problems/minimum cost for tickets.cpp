class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int day=costs[0];
        int week=costs[1];
        int month=costs[2];
        int n=days.size();
        vector<int> dp(n);
        dp[0]=min(day,min(week,month));
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+day;
            int j=i;
            while(j>=0&&days[i]-days[j]<7)
            {
                j--;
            }
            dp[i]=min(dp[i],j==-1?week:week+dp[j]);
            j=i;
            while(j>=0&&(days[i]-days[j])<30)
            {
                j--;
            }
            dp[i]=min(dp[i],j==-1?month:month+dp[j]);
        }
        return dp[n-1];
        
    }
};
