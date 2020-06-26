class Solution {
public:
     unordered_map<int,unordered_set<int>> mp;
    bool dfs(int s,int d,unordered_map<int,unordered_map<int,bool>> &mem)
    {
        
            
       
        if(mem.count(s)&& mem.at(s).count(d))
            return mem[s][d];
        
        
        
            for(auto it:mp[s])
            {
              
                if(it==d||dfs(it,d,mem))
                    return mem[s][d]=true;
               
                
            }
       
     
       return mem[s][d]=false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
       
        
        for(int i=0;i<pre.size();i++)
        {
            mp[pre[i][0]].insert(pre[i][1]);
        }
        vector<bool> ans;
       
        unordered_map<int,unordered_map<int,bool>> mem;
        for(int i=0;i<queries.size();i++)
        {
          ans.push_back(dfs(queries[i][0],queries[i][1],mem));
        }
        return ans;
        
    }
};
