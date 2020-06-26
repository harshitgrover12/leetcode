class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> mp;
    
    int bfs(int dest,int s)
    {
            if(s==dest)
                return 0;
            queue<pair<int,int> > q;
            q.push(make_pair(s,0));   
            set<pair<int,int>> st;
            st.insert({0,0});
            int cnt=-1;
            while(!q.empty())
            {
              cnt++;
            int no=q.size();
                while(no--)
                {
                auto node=q.front();
                q.pop();
                int c=node.second;
                int u=node.first; 
                    if(u==dest)
                        return cnt;
                if(c==0)
                {
                for(auto it:mp[u])
                {   
                   if(st.find(it)==st.end())
                   {
                        st.insert(it);
                        q.push(it);
                   }
                  
                }
                }
                    else if(c==1)
                    {
                        for(auto it:mp[u])
                        {
                            if(st.find(it)==st.end()&&it.second==2)
                            {
                                    st.insert(it);
                                     q.push(it);
                            }
                        }
                    }
                     else 
                    {
                        for(auto it:mp[u])
                        {
                            if(st.find(it)==st.end()&&it.second==1)
                            {
                                    st.insert(it);
                                     q.push(it);
                            }
                        }
                    }
                }
            }
                    return -1;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
    {
        
        for(int i=0;i<red_edges.size();i++)
        {
            mp[red_edges[i][0]].push_back(make_pair(red_edges[i][1],1));
        }
        for(int i=0;i<blue_edges.size();i++)
        {
            mp[blue_edges[i][0]].push_back(make_pair(blue_edges[i][1],2));
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        ans.push_back(bfs(i,0));        
        return ans;
        
    }
};
