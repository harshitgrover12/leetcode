class Solution {
public:
    int numTeams(vector<int>& a) {
        
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
        int behind1=0;
        int ahead1=0;
        int behind2=0;
        int ahead2=0;
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                    behind1++;
                else
                    behind2++;
             }
             for(int j=i+1;j<a.size();j++)
             {
                if(a[j]>a[i])
                {
                    ahead1++;
                }
                 else
                     ahead2++;
             }
            ans+=(ahead1*behind1)+(ahead2*behind2);
        }
       
        return ans;
    }
};
