int Solution::threeSumClosest(vector<int> &a, int target) 
{
    sort(a.begin(),a.end());
    int n=a.size();
    int mini=INT_MAX;
    int p;
    for(int i=0;i<a.size()-2;i++)
    {
        int s=i+1; 
        int e=n-1;
        while(s<e)
        {
                if(abs(a[i]+a[s]+a[e]-target)<mini)
                     {
                        mini=abs(a[i]+a[s]+a[e]-target);
                            p=a[i]+a[s]+a[e];
                        }
             if(a[i]+a[s]+a[e]>target)
             {
                 e--;
                
             }
             else if(a[i]+a[e]+a[s]<target)
             {
                 s++;
             }
             else
             {
                 return p;
             }
        }
      
       
        
        
    }
    return p;
}


