bool cmp(pair<int,int>&a,pair<int,int>&b)
{
        return a.second<b.second;
}
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        map<int,int> mp;
        int sum=0;
        vector<pair<int,int>> pr;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
           
            if(sum==target)
            {
                pr.push_back({1,i+1});
            }
             if(mp[sum-target]!=0&&mp[sum-target]<=i)
            {
                pr.push_back({mp[sum-target]+1,i+1});
            }
             mp[sum]=i+1;
        }
        if(pr.size()==0)
            return 0;
        sort(pr.begin(),pr.end(),cmp);
        pair<int,int> p=pr[0];
        int c=1;
        cout<<p.first<<" "<<p.second<<" "<<endl;
        for(int i=1;i<pr.size();i++)
        {   cout<<pr[i].first<<" "<<pr[i].second<<endl;
            if(pr[i].first>p.second)
            {
                c++;
                p=pr[i];
            }
        }
        return c;
    }
};
