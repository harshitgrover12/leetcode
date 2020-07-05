class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xr=0;
        for(int i=0;i<nums.size();i++)
        {
            xr=xr^nums[i];
        }
        int y=0;
        int temp=xr;
        int pos=0;
        while((temp&1)!=1)
        {
            pos++;
            temp=temp>>1;
        }
        int mask=1<<pos;
        
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&mask)>0)
            {
                y=y^nums[i];
            }
        }
        int x=xr^y;
        return {x,y};
        
             
    }
};
