class Solution {
public:
    
    struct cmp {
    bool operator() (string a, string b) const {
        return a<b;
    }
};
    unordered_map<string,vector<string> > mp;
    vector<string> ans;
    void dfs(string src)
    {
       
            while(!mp[src].empty())            
            {
                string s=mp[src].back();
                mp[src].pop_back();
                
                dfs(s);
                
            }
        ans.push_back(src);
            
            
            
        
         return;
            
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++)
        {
            
            mp[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto &it:mp)
        {
            sort(it.second.begin(),it.second.end(),greater<string>());
        }
        
        
       
       dfs("JFK");
           
        
        
    reverse(ans.begin(),ans.end());
         return ans;
    }
};
