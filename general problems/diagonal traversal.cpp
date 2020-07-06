bool cmp(pair<int,int> &a,pair<int,int>&b)
{
    if(a.first+a.second==b.first+b.second)return a.first>b.first;
    return a.first+a.second<b.first+b.second;
}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int,int>> help;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                
                help.push_back({i,j});
            }
            
        }
        sort(help.begin(),help.end(),cmp);
        vector<int> ans;
        
        for(auto it:help)
        {
            ans.push_back(nums[it.first][it.second]);
        }
        return ans;
    }
};
