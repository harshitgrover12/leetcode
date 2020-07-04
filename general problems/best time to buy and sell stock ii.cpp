class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mini)
                mini=prices[i];
            else
            {
                sum+=prices[i]-mini;
                mini=prices[i];
            }
        }
        
        return sum;
        
    }
};
