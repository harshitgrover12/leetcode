class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(!st.empty()&&tolower(st.top())==tolower(s[i])&&st.top()!=s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        string d="";
        while(!st.empty())
        {
            d+=st.top();
            st.pop();
        }
        string ans="";
        for(int i=d.length()-1;i>=0;i--)
            ans+=d[i];
        return ans;
    }
};
