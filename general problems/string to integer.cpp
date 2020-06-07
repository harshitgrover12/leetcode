class Solution {
public:
    int myAtoi(string s) {
        
        string d="";
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' '&&flag==1)
                break;
           if(s[i]!=' ')
           {
               d+=s[i];
               flag=1;
           }
            
        }
        cout<<d[0];
        string e="";
        int sign=1;
        if(d[0]=='+'||d[0]=='-'||isdigit(d[0]))
        {
           
        for(int i=0;i<d.length();i++)
        {
             if(d[i]=='+'&&i==0)
            {sign=1;
            continue;}
            if(d[i]=='-'&&i==0)
            {sign=-1;
            continue;
            }
            
            if(isdigit(d[i]))
                e+=d[i];
            else break;
        }
        }
       
        long long int dig=0;
        int i=0;
     while(i<e.length()&&dig<INT_MAX)
     {
            dig=(dig*10+e[i]-'0');
         i++;
     }
        dig=dig*sign;
        
        if(dig>INT_MAX)
            return INT_MAX;
        else if(dig<INT_MIN)
             return INT_MIN;
        else
        return dig;
        
    }
};
