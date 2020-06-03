class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            a[nums[i]]=i+1;
            
        }
        vector<int> sol;
        for(int i=0;i<n;i++)
        {
            
                if(a[target-nums[i]]!=0&&a[target-nums[i]]!=i+1)
                {
                    sol.push_back(min(i,a[target-nums[i]]-1));
                    sol.push_back(max(i,a[target-nums[i]]-1));
                    break;
                }
            
           
        }
        return sol;
        
    }
};
