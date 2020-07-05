class Solution {
public:
    int checkadj(int i,int j,vector<vector<char>>board)
    {
        int cnt=0;
        int r[8]={-1,-1,0,1,1,1,0,-1};
        int c[8]={0,1,1,1,0,-1,-1,-1};
            for(int k=0;k<8;k++)
            {
                int x=i+r[k];
                int y=j+c[k];
                if(x>=0&&x<board.size()&&y>=0&&y<board[0].size())
                {
                    if(board[x][y]=='M')
                    {
                        if(i==2&&j==1)
                            cout<<x<<" "<<y<<endl;
                        cnt++;
                    }

                }
                
            }
        return cnt;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        queue<pair<int,int>> q;
        q.push({click[0],click[1]});
        int r[8]={-1,-1,0,1,1,1,0,-1};
        int c[8]={0,1,1,1,0,-1,-1,-1};
        map<pair<int,int>,bool> visited;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
           int i=f.first;
            int j=f.second;
                        if(visited[{i,j}])
                continue;
          

            visited[{i,j}]=true;
            if(board[i][j]=='M')   
            {
                board[i][j]='X';
                return board;
            }
            
            board[i][j]='B';
            int cnt=checkadj(i,j,board);
        
            if(cnt>0)
            board[i][j]=cnt+'0';
            else
            {
                 for(int k=0;k<8;k++)
            {
                int x=i+r[k];
                int y=j+c[k];
                if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&!visited[{x,y}])
                {
                    q.push({x,y});

                }
                
            }
            }  
            
        }
        return board;
    }
};
