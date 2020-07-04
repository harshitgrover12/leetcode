class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_sum--;
            if(max_sum<0)
                return false;
            
            if(nums[i]>max_sum)
                max_sum=nums[i];
        }
        return true;
        
    }
};
