bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    return a.second<b.second;
}
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int excess=0;
        int def=0;
        int start=0;
        for(int i=0;i<gas.size();i++)
        {
                int diff=gas[i]-cost[i];
            excess+=diff;
            if(excess<0)
            {
                def+=excess;
                start=i+1;
                excess=0;
                
            }
                
        }
        if(excess+def>=0)
            return start;
        else return -1;
        
    }
};
