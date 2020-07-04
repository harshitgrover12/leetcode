bool cmp(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        int index=0;
        int n=intervals.size();
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=intervals[index][1])
            {
                intervals[index][1]=max(intervals[index][1],intervals[i][1]);
            }
            else
            {
                intervals[++index]=intervals[i];
            }
            
        }
        intervals.erase(intervals.begin()+index+1,intervals.begin()+n);
        return intervals;

        
        
        
    }
};
