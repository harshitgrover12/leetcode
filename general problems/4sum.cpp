class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> sol;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int l=j+1;
                int k=n-1;
                while(l<k)
                {
                    if(nums[i]+nums[j]+nums[k]+nums[l]>target)
                    {
                        k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]<target)
                    {
                        l++;
                    }
                    else
                    {
                        sol.push_back(nums[i]);
                        sol.push_back(nums[j]);
                        sol.push_back(nums[l]);
                        sol.push_back(nums[k]);
                        ans.push_back(sol);
                        sol.clear();
                        while(l<k&&nums[l]==nums[l+1])
                            l++;
                        while(l<k&&nums[k]==nums[k-1])
                            k--;
                        l++;
                        k--;
                        
                    }
                }
            }
            
        }
        return ans;
        
    }
};
