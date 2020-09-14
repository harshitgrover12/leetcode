string Solution::minWindow(string S, string B) {
    int n=S.length();
    int m=B.length();
    unordered_map<char,int> mp;
    int s=0;
    for(int i=0;i<m;i++)
    {
        mp[B[i]]++;
    }
    unordered_map<char,int> mp1;
    int mini=INT_MAX;
    int p=-1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        mp1[S[i]]++;
        if(mp[S[i]]!=0&&mp1[S[i]]<=mp[S[i]])
        cnt++;
       
        if(cnt==m)
        {
            while(mp[S[s]]<mp1[S[s]]||mp1[S[s]]==0)
            {
            
                if(mp[S[s]]<mp1[S[s]])
                mp1[S[s]]--;
                s++;
        }
           int length=i-s+1;
           if(length<mini)
           {
               mini=length;
               p=s;
           }
        }
        
    }
    //'a' 'w'
    return p!=-1?S.substr(p,mini):"";
    
}
//TC? O(N)
//ADOBECODEBANC
//s=0
//A->1
//ADOBEC
//BANC
//m
//ABC
//n1=3
//mp[s]<mp1[s] s++;



