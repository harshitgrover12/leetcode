class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
        }
        
        vector<int> a;
        vector<int> ans;
        int previous=0;
        for(int j=0;j<s.length();j++)
        {
            mp2[s[j]]++;

            if(mp1[s[j]]==mp2[s[j]])
            {
                a.push_back(s[j]);
                
                if(a.size()==mp2.size())
                {
                    ans.push_back(j+1-previous);
                    previous=j+1;
                    
                    
                }
            }
        }
        return ans;
        
    }
};
