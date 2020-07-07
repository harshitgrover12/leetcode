class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;k++)
                    {
                        int x=i+r[k];
                        int y=j+c[k];
                        if(x<0||x>grid.size()-1)
                            cnt++;
                        if(y<0||y>grid[0].size()-1)
                            cnt++;
                        if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size())
                        {
                            if(grid[x][y]==0)
                                cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
        
    }
};
