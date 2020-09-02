bool cmp(vector<int> &a,vector<int> &b)
    {
        
        return a[0]<=b[0];
    }
class Solution {
public:
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int,int> mp;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            mp[intervals[i][0]]=i;
        }
        vector<vector<int>> sub=intervals;
        sort(sub.begin(),sub.end(),cmp);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
                int s=0;
                int e=n-1;
                int ind=-1;
                while(s<=e)
                {
                    int mid=(s+e)/2;
                    if(sub[mid][0]>=intervals[i][1])
                    {
                        ind=mid;
                        e=mid-1;
                    }
                    else
                        s=mid+1;
                }
            if(ind>=0)
                ans[i]=mp[sub[ind][0]];
            else
                ans[i]=-1;
        }
        return ans;
        
    }
};
