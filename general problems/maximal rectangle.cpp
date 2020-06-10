class Solution {
public:
    int calcArea(int dp[],int n)
    {
        stack<int> st;
        st.push(0);
        int max_area=0;
        int i;
        for( i=1;i<n;i++)
        {
            if(!st.empty()&&dp[st.top()]>dp[i])
            {
                int x;
                while(!st.empty()&&dp[i]<dp[st.top()])
                {
                    x=st.top();
                    st.pop();
                    if(st.empty())
                    {
                        max_area=max(max_area,i*dp[x]);
                    }
                    else
                        max_area=max(max_area,(i-st.top()-1)*dp[x]);
                }
                
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
             int x;
                
                    x=st.top();
                    st.pop();
                    if(st.empty())
                    {
                        max_area=max(max_area,i*dp[x]);
                    }
                    else
                        max_area=max(max_area,(i-st.top()-1)*dp[x]);
            
        }
        
        return max_area;
            
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size())
            return 0;
        
        int dp[matrix[0].size()];
        
       for(int i=0;i<matrix[0].size();i++)
           dp[i]=0;
        int max_area=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                
                if(matrix[i][j]-'0'==0)
                    dp[j]=0;
                else
                    dp[j]=dp[j]+matrix[i][j]-'0';
            }
           
            int maxi=calcArea(dp,matrix[0].size());
            max_area=max(max_area,maxi);
            
            
        }
        return max_area;
    }
};
