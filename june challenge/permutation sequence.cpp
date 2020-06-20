#define ll long long
class Solution {
public:
    ll factorial(ll n)
    {
            ll fact=1;
        for(int i=2;i<=n;i++)
        {
            fact=fact*i;  
        }
        return fact;
    }
    string sorti(string s,int n)
    {
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=1;
        }
        for(int i=n;i>=1;i--)
        {
            if(!mp[i+'0'])
                s+=i+'0';
        }
        return s;
    }
    int findno(string s,int count,int n)
    {
        int c=0;
        map<char,int> mp;
            for(int i=0;i<s.length();i++)
            {
               mp[s[i]]=1;
            }
        for(int i=1;i<=n;i++)
        {
            if(!mp[i+'0'])
            {
                c++;
                if(c==count)
                    return i;
            }
        }
        return 1;
    }
    
    
    string getPermutation(int n, int k) {
        string s="";
        int d=k;
        int no;
        if(n==1)
            return "1";
        if(n==2)
        {
            if(k==1)
                return "12";
            else 
                return "21";
        }
        for(int i=1;i<=n-2;i++)
        {
                if(d==0)
                {
                    string d=sorti(s,n);
                    return d;
                    
                }
                 ll fact=factorial(n-i);
                 float r=ceil((float)d/(ll)fact);
                 int r1=(int)r;
                 int m=r1;
                 if(i!=1)
                  m=findno(s,r1,n);
                 s+=m+'0';
                 d=d%fact;                   
        }
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]=1;
        }
        if(d==1)
        {
        for(int i=1;i<=n;i++)
        {
            if(!mp[i+'0'])
            {s+=i+'0';break;}
        }
        for(int i=n;i>=1;i--)
        {
            if(!mp[i+'0'])
            {s+=i+'0';break;}
        }
        }
        else
        {
        for(int i=n;i>=1;i--)
        {
            if(!mp[i+'0'])
            {s+=i+'0';break;}
        }
        for(int i=1;i<=n;i++)
        {
            if(!mp[i+'0'])
            {s+=i+'0';break;}
        }
            
        }
        return s;
        
        
    }
};
