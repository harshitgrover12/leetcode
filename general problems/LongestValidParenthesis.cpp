class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.length();
        stack<int> st;
        st.push(-1);
        int max_length=0;
        for(int i=0;i<n;i++)
        {
            
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    max_length=max(max_length,i-st.top());
                }
                else
                    st.push(i);
            }
        }
        return max_length;
    }
};
