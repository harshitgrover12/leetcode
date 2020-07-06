class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ans;
            if(n==0)
            return ans;
        int m=matrix[0].size();
        int l=0;
        int u=n-1;
        int cl=0;
        int cu=m-1;
        int i=0;
        int cnt=0;
        

        while(1)
        {
            if(cnt==n*m)
                break;
            if(i%4==0)
            {
                for(int j=cl;j<=cu;j++)
                {
                    ans.push_back(matrix[l][j]);
                    cnt++;
                }
                l++;
            }
            else if(i%4==1)
            {
                for(int j=l;j<=u;j++)
                {
                    ans.push_back(matrix[j][cu]);
                    cnt++;
                }
                cu--;
            }
            else if(i%4==2)
            {
                for(int j=cu;j>=cl;j-- )
                {
                    ans.push_back(matrix[u][j]);
                    cnt++;
                }
                u--;
            }
            else if(i%4==3)
            {
                for(int j=u;j>=l;j--)
                {
                    ans.push_back(matrix[j][cl]);
                    cnt++;
                }
                cl++;
            }
            i++;
        }
        return ans;
        
    }
};
