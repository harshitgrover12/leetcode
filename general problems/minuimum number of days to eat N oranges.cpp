
class Solution {
public:
     map<int,int> dp;
    int helper(int n)
    {
      if(n<=1)
          return n;
        if(dp.count(n)!=0)
            return dp[n];
        dp[n]=1+min(n%2+helper(n/2),n%3+helper(n/3));
        return dp[n];
        
    }
    int minDays(int n) {
       
        int help=helper(n);
        return help;
        
        
    }
};
