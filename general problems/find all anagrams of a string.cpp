#include <bits/stdc++.h>
using namespace std;
bool isvalid(int x,int y,int n,int m,vector<vector<int> > a)
{
    if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==1)
    return true;
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        cin>>n>>m;
        vector<vector<int> > a(n,vector<int>(m));
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<pair<int,int> > pr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                pr.push_back({i,j});
            }
        }
        
        int maxi=0;
        for(int i=0;i<pr.size();i++)
        {
            
            if(!visited[pr[i].first][pr[i].second])
            {
                queue<pair<int,int> > q;
                q.push(pr[i]);
                int cnt=1;
                while(!q.empty())
                {
                    auto it=q.front();
                    q.pop();
                    int x=it.first;
                    int y=it.second;
                    visited[x][y]=true;
                    if(isvalid(x-1,y,n,m,a))
                    {
                        cnt++;
                        q.push({x-1,y});
                    }
                    if(isvalid(x-1,y+1,n,m,a))
                    {
                        cnt++;
                        q.push({x-1,y+1});
                    }
                    if(isvalid(x,y+1,n,m,a))
                    {
                        cnt++;
                        q.push({x,y+1});
                    }
                     if(isvalid(x+1,y+1,n,m,a))
                     {
                         q.push({x+1,y+1});
                         cnt++;
                     }
                    if(isvalid(x+1,y,n,m,a))
                    {
                        q.push({x+1,y});
                        cnt++;
                    }
                    if(isvalid(x+1,y-1,n,m,a))
                    {
                        q.push({x+1,y-1});
                        cnt++;
                    }
                    if(isvalid(x,y-1,n,m,a))
                    {
                        q.push({x,y-1});
                        cnt++;
                    }
                    if(isvalid(x-1,y-1,n,m,a))
                    {
                        q.push({x-1,y-1});
                        cnt++;
                    }
                    
                    
                }
                maxi=max(cnt,maxi);
            }
            
        }
        cout<<maxi<<endl;
    }
    
    
	
	return 0;
}
