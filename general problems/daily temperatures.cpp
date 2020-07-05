class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size());
        int n=t.size();
        stack<pair<int,int>> st;
        st.push({t[n-1],n-1});
        
        for(int i=n-2;i>=0;i--)
        {
            if(t[i]<t[i+1])
            {
                st.push({t[i],i});
                ans[i]=1;
            }
            else
            {
                while(!st.empty()&&t[i]>=st.top().first)
                {
                    st.pop();
                }
                if(st.empty())
                    ans[i]=0;
                else
                {
                    ans[i]=st.top().second-i;
                }
                st.push({t[i],i});
            }
                
        }
        
        
        return ans;
        
    }
};
