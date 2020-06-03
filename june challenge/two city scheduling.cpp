 bool cmp(pair<int,int> &a,pair<int,int>&b)
    {
    
        return abs(a.second-a.first)<abs(b.second-b.first);
    }
class Solution {
public:
   
    int twoCitySchedCost(vector<vector<int>>& costs) {
        map<int,int> mp;
        int fcost=0;
        int scost=0;
        vector<pair<int,int>> c;
        vector<pair<int,int>> d;
        int n=costs.size();
        for(int i=0;i<costs.size();i++)
        {
            
            if(costs[i][0]<costs[i][1])
            {
                mp[0]++;
                fcost+=costs[i][0];
                c.push_back(make_pair(costs[i][0],costs[i][1]));
               
            }
            else 
            {
                mp[1]++;
                scost+=costs[i][1];
                d.push_back(make_pair(costs[i][0],costs[i][1]));
            }
        }
        sort(c.begin(),c.end(),cmp);
        sort(d.begin(),d.end(),cmp);
        if(mp[0]==mp[1])
            return scost+fcost;
        else if(mp[0]>mp[1])
        {
            int min_cost=INT_MAX;
            int r=n/2-mp[1];
            int fo=0;
            int co=0;
          for(int i=0;i<r;i++)
          {
            co+=c[i].second;
            fo+=c[i].first;
          }
            return scost+fcost-fo+co;
            
        }
        else{
            int min_cost=INT_MAX;
            int r=n/2-mp[0];
            int fo=0;
            int co=0;
          for(int i=0;i<r;i++)
          {
            co+=d[i].second;
            fo+=d[i].first;
          }
            return scost+fcost-co+fo;
                
        }
        
    }
};
