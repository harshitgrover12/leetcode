class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int d=0;
    void dfs(int s,vector<int> &visited)
    {
            visited[s]=1;
        for(auto it:mp[s])
        {
            if(visited[it]==1)
                d++;
            if(!visited[it])
                dfs(it,visited);
        }
        visited[s]=2;
        
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        
        for(auto it:pre)
        {
            mp[it[1]].push_back(it[0]);    
        }
        vector<int> visited(num,0);
        int cnt=0;
        for(int i=0;i<num;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited);
            }
        }
       if(!d)
            return true;
        else return false;
    
        
    }
};
