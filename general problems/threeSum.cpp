class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();

       
        sort(nums.begin(),nums.end());
        
        vector<int> sol;
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
               continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]>0)
                    k--;
                else if(nums[i]+nums[j]+nums[k]<0)
                    j++;
                else
                {
                    sol.push_back(nums[i]);
                    sol.push_back(nums[j]);
                    sol.push_back(nums[k]);
                    ans.push_back(sol);
                    sol.clear();
                    while(j<k&&nums[j]==nums[j+1])
                        j++;
                    while(j<k&&nums[k]==nums[k-1])
                        k--;
                    j++;
                    k--;
                        
                }
                
            }
        }
        return ans;
        
                    
      
        
    }
};
