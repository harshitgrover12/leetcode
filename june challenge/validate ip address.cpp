class Solution {
public:
    string validIPAddress(string s) {
        int n=s.length();
        string d="Neither";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                d="IPv4";
                break;
            }
            if(s[i]==':')
            {
                d="IPv6";
            }
        }
        if(d=="IPv4")
        {
            int no=0;
            string f="";
            int count=0;
            for(int i=0;i<s.length();i++)
            {
                 if(s[i]=='.'&&i==s.length()-1||f.length()>3||s[i]=='-')
                     return "Neither";
                if(s[i]=='.')
                {count++;
                    if(no<0||no>255||(f.length()>1&&f[0]=='0')||f.length()==0)
                    {d="Neither";return d;}
                    no=0;
                    f="";
        
                   
                }
                else if(isdigit(s[i]))
                {
                    no=no*10+s[i]-'0';
                    f+=s[i];
                }
                else if(!isdigit(s[i]))
                    return "Neither";
            }
             if(no<0||no>255||(f.length()>0&&f[0]=='0')||f.length()==0||count!=3)
                    {d="Neither";return d;}
                    no=0;
        
        }
        else if(d=="IPv6")
        {
            string f="";
            int count=0;
            for(int i=0;i<s.length();i++)
            {
                
                 if(s[i]==':'&&i==s.length()-1||(isalpha(s[i])&&(toupper(s[i]))>'F')||s[i]=='-')
                    return "Neither";
                else if(s[i]==':')
                {   cout<<f<<" ";
                    count++;
                    if(f==""||(f.length()>4))
                    {d="Neither";return d;}
                    
                    
                    f="";
                 continue;
        
                   
                }
                
                 f+=s[i];
             
            }
             if(f==""||count!=7||f.length()>4)
                    {d="Neither";return d;}
                   
                    f="";
        
        }
        return d;
        
    }
};
