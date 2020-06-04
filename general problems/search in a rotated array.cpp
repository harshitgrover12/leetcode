class Solution {
public:
    int search(vector<int>& a, int item ){
        
        int n=a.size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(a[mid]==item)
            {
                return mid;
            }
            if(a[s]<=a[mid])
            {
                if(a[s]<=item&&item<a[mid])
                {
                    e=mid-1;
                }
                else
                {
                    
                    s=mid+1;
                }
            }
            else
            {
                if(a[mid]<item&&item<=a[e])
                {
                    s=mid+1;
                }
                else 
                    e=mid-1;
            }
        }
        return -1;
    }
};
