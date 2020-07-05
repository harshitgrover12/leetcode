class Solution {
public:
    

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses);
        unordered_map<int,vector<int>> mp;
                vector<int> ans;
        for(auto it:pre)
        {
           
            mp[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto it:mp[f])
            {
                if(--indegree[it]==0)
                    q.push(it);
            }
            cnt++;
            
        }
        if(cnt!=numCourses)
            return {};
        return ans;
        
        
        
        
    }
};
