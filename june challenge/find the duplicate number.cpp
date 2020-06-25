class Solution {
public:
 
    int findDuplicate(vector<int>& nums) {
        vector<int> bits(32);
        for(int i=0;i<=31;i++)
        {
            for(int j=1;j<nums.size();j++){
                
                
                    bits[i]+=(1<<i)&j;
            }
        }
        int dup=0;
        for(int i=0;i<=31;i++)
        {
            
        int cnt=0;
            for(int j=0;j<nums.size();j++)
            {
                cnt+=((1<<i)&nums[j]);
            }
            if(cnt>bits[i])
            dup|=(1<<i);
            
        }
        return dup;
            
    }
};
