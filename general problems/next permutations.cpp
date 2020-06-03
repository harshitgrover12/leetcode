class Solution {
public:
    void swap(int &a,int &b)
    {
        int c=a;
        a=b;
        b=c;
    }
  
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        if(nums.size()<=1)
            return;
        int left;
        for( left=n-1;left>=0;left--)
        {
            if(nums[left]<nums[left+1])
            {
                break;
            }
        }
        int right;
        for(right=left+1;right<=n;right++)
        {
            if(left<0||nums[right]<=nums[left])
                break;
            
        }
        if(left>=0&&right-1<=n)
            swap(nums[left],nums[right-1]);
        
        int j=n;
        int i=left+1;
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
    }
};
