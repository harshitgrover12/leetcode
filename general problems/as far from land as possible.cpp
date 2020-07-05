class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res=-1;
        vector<vector<int> > dist(grid.size());
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++)
        {
            dist[i]=vector<int>(grid[0].size(),INT_MAX);
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                if(grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({i,j,i,j});
                    
                }
            }
        }
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        
        while(!q.empty())
        {
                int n=q.size();
            while(n--)
            {
                auto p=q.front();
                q.pop();
                int i=p[0];
                int j=p[1];
                int pi=p[2];
                int pj=p[3];
                if(grid[i][j]==0)
                res=max(res,dist[i][j]);
                
                for(int k=0;k<4;k++)
                {
                    int x=i+r[k],y=j+c[k];
                    if(x>=0&&x<=grid.size()-1&&y>=0&&y<=grid[0].size()-1&&grid[x][y]==0)
                    {
                        int distance=abs(x-pi)+abs(y-pj);
                        if(dist[x][y]>distance)
                        {dist[x][y]=distance;
                        q.push({x,y,pi,pj});
                        }
                    }
                }
                
            }
        }
        return res;
        
    }
};
