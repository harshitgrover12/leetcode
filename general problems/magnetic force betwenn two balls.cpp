#define ll long long 
class Solution {
public:
    bool isValid(vector<int> &pos,ll mid,int m)
    {
        int j=1;
        int prev=0;
        for(int i=1;i<m;i++)
        {
            while(j<pos.size()&&pos[j]<pos[prev]+mid) j++;
            if(j>=pos.size())
                return false;
            prev=j;
        }
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        ll l=1;
        ll r=position[position.size()-1]-position[0];
        while(l<=r)
        {
                ll mid=(l+r)/2;
                
                if(isValid(position,mid,m ))    
                {
                   
                    l=mid+1;
                }
            else
                r=mid-1;
        }
        return r;
        
        
    }
};
