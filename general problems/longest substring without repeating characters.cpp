class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int st=0;
        unordered_map<char,int> mp;
        int c=0;
        int maxi=INT_MIN;
        int i;
        for( i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            
            if(mp[s[i]]>1)
            {
                if(i-st>maxi)
                    maxi=i-st;
                while(mp[s[st]]==1)
                {
                    mp[s[st]]--;
                    st++;
                }
                mp[s[st]]--;
                st++;
                
                
            }
            
            
        }
         if(i-st>maxi)
                    maxi=i-st;
        return maxi;
        
    }
};
