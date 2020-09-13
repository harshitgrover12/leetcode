class Solution {
public:
    string toGoatLatin(string S) {
        istringstream ss(S);
        string ans="";
        int cnt=1;
        vector<string> stor;
        while(ss)
        {
            string s;
            ss>>s;
            if(s.length()==0)
                break;
            char first=s[0];
            if(first==' ')
                break;
            char l=tolower(first);
            
            string d(cnt,'a');
             cnt++;
            if(l=='a'||l=='e'||l=='i'||l=='o'||l=='u')
            {
                
                s=s+"ma"+d;
            }
            else
            {
                if(s.length()>1)
                s=s.substr(1)+first+"ma"+d;
                else
                s=s+"ma"+d;
            }
            
            stor.push_back(s);
           
            
            
        }
        for(int i=0;i<stor.size()-1;i++)
        {
            ans+=stor[i]+" ";
        }
        ans+=stor[stor.size()-1];
        return ans;
        
        
    }
};
