class Solution {
public:
    int find_set(int i,vector<int> &parent)
    {
            if(parent[i]==-1)
                return i;
        return parent[i]=find_set(parent[i],parent);
    }
    void union_set(int a,int b,vector<int> &ranking,vector<int> &parent)
    {
        int s1=find_set(a,parent);
        int s2=find_set(b,parent);
        if(s1!=s2)
        {
            if(ranking[s1]<ranking[s2])
            {
                parent[s1]=s2;
                ranking[s2]+=ranking[s1];
            }
            else
            {
                parent[s2]=s1;
                ranking[s1]+=ranking[s2];
            }
        }
    }
   
    int largestComponentSize(vector<int>& A) {
        int n=A.size();
        int maxi=*max_element(A.begin(),A.end());
        vector<int> sieve(maxi+1);
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<=maxi;i++)
            sieve[i]=i;
        for(int i=2;i*i<=maxi;i++)
        {
            if(sieve[i]==i)
            {
                for(int j=i*i;j<=maxi;j+=i)
                {
                    
                        if(sieve[j]==j)
                        {
                            
                            sieve[j]=i;
                        }
                }
            }
        }
        // for(int i=1;i<=maxi;i++)
        //     cout<<sieve[i]<<" ";
        vector<int> ranking(n,1);
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++)
        {
            int no=A[i];
            while(no!=1)
            {
                mp[sieve[no]].insert(i);
                no=no/(sieve[no]);
            }
        }
     
        
        for(auto it:mp)
        {
            unordered_set<int> s=it.second;
            int par=*s.begin();
            s.erase(s.begin());
            
            for(int x:s)
            {
                
                union_set(par,x,ranking,parent);
            }
            
        }
        return *max_element(ranking.begin(),ranking.end());
        
       
    }
};
