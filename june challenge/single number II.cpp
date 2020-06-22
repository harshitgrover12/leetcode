class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int k=31;k>=0;k--)
        {
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                if((nums[i]>>k)&1)
                {
                    count++;
                }
                
            }
            if(count>0)
            {
                count=count%3;
                if(count==1)
                    ans+=1<<k;
            }
        }
        return ans;
        
    }
};
