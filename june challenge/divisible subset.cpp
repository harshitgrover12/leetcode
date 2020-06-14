class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        map<int,int> mp;
        int dp[nums.size()];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            dp[i]=1;
        
        int maxi=INT_MIN;
        int index=1;
        vector<int> a;
    
        if(nums.size()==1)
        {
            a.push_back(nums[0]);
            return a;
        }
        if(nums.size()==0)
            return nums;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                
                if(nums[j]%nums[i]==0&&dp[j]<dp[i]+1)
                {
                    dp[j]=dp[i]+1;
                    
                    mp[j+1]=i+1;
                    if(dp[j]>maxi)
                    {
                        maxi=dp[j];
                        index=j+1;
                        
                        
                    }
                    
                    
                }
            }
        }
        for(int i=0;i<nums.size();i++)
            cout<<dp[i]<<" ";
        vector<int> b;
        a.push_back(nums[index-1]);
        while(mp[index]!=0)
        {
            index=mp[index];
            a.push_back(nums[index-1]);
        }
        for(int i=a.size()-1;i>=0;i--)
        {
            b.push_back(a[i]);
        }
        return b;
    }
};
