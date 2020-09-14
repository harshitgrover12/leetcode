class Solution {
public:
    

 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int fresh=0;
        
        queue<pair<int,int>> q;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        int maxi=INT_MIN;
       
        for(int i=0;i<grid.size();i++)
        {
                for(int j=0;j<grid[0].size();j++)
                {
                    
                    if(grid[i][j]==0)
                        dp[i][j]=0;
                    else if(grid[i][j]==1)
                        dp[i][j]=INT_MAX;
                    else
                    {
                        q.push({i,j});
                    }
                }
        }
        int x[]={-1,0,1,0};
        int y[]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int x1=p.first;
            int y1=p.second;
            for(int i=0;i<4;i++)
            {
                int x2=x[i]+x1;
                int y2=y[i]+y1;
                if(x2>=0&&x2<grid.size()&&y2>=0&&y2<grid[0].size()&&dp[x2][y2]==INT_MAX)
                {
                    if(dp[x2][y2]>dp[x1][y1]+1)
                        
                    {
                        dp[x2][y2]=dp[x1][y1]+1;
                    q.push({x2,y2});
                     }
                }
                
            }
        }
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(dp[i][j]==INT_MAX)
                        return -1;
                    maxi=max(dp[i][j],maxi);
                }
            }
        return maxi;
            
        
        
 
        
        
        
        
    }
};
