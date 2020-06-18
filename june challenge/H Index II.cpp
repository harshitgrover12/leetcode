class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int s=0;
        int e=citations.size()-1;
        
        int ans=-1;
        if(n==0)
            return 0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(n-mid<=citations[mid])
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        if(ans==-1)
            return 0;
        return n-ans;
        
    }
    
};
