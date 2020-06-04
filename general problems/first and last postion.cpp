class Solution {
public:
    vector<int> searchRange(vector<int>& a, int item) {
        int s=0;
        int e=a.size()-1;
        int start=-1;
        int end=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(a[mid]==item)
            {
                if(mid-1>=0&&a[mid-1]==a[mid])
                {
                    e=mid-1;
                }
                else
                { start=mid;break;}
            }
            else if(a[mid]>item)
            {
                e=mid-1;
            }
            else
                s=mid+1;
        }
        s=0;
        e=a.size()-1;
         while(s<=e)
        {   int mid=(s+e)/2;
            if(a[mid]==item)
            {
                if(mid+1<a.size()&&a[mid+1]==a[mid])
                {
                    s=mid+1;
                }
                else
                { end=mid;break;}
            }
            else if(a[mid]>item)
            {
                e=mid-1;
            }
            else
                s=mid+1;
        }
        vector<int> b;
        b.push_back(start);
        b.push_back(end);
        return b;
        
        
    }
};
