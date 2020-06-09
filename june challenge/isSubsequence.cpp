class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0;
        int j=0;
        while(i<s.length()&&j<t.length())
        {
            if(t[j]==s[i])
                i++;
            j++;
        }
        if(i!=s.length())
            return false;
        else return true;
        
    }
};
