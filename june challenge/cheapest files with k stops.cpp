class Solution {
public:
    map<int,vector<pair<int,int>>> mp;
    int minni=INT_MAX;
    int dfs(int n,int src,int dst,int k,int c)
    {
            if(src==dist)
            {
                return 0;
            }
        
        for(auto i=mp[src].begin();i!=mp[src].end();i++)
        {
             c+=i.second+dfs(n,i.first,dist,k-1,c);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       
        
        for(int i=0;i<flights.size();i++)
        {
           
                mp[flights[i][0].push_back(makepair(flights[i][1],flights[i][2]));
                   
        }
                   int c=0;
        int ans=dfs(n,src,dst,K,c);
            
        
    }
};
