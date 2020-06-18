class Solution {
public:
    int numDecodings(string s) {
        vector<int> a(s.length()+1);
        a[0]=1;
        for(int i=1;i<a.size();i++)
            a[i]=1;
        if(s[0]=='0')
            a[1]=0;
        for(int i=2;i<=s.length();i++)
        {
           int no=0;
            no=no*10+s[i-2]-'0';
            no=no*10+s[i-1]-'0';
            if(s[i-1]=='0')
            {
                
                if(no==10||no==20)
                    a[i]=a[i-2];
                else 
                    return 0;
            }
           else  if(no>=1&&no<=26&&s[i-2]!='0')
                a[i]=a[i-1]+a[i-2];
            else 
                a[i]=a[i-1];
            
            
        }
        if(s.length()==0)
            return 0;
        return a[s.length()];
    }
};
