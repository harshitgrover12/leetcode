class Solution {
public:
    vector<int> cum;
    
    Solution(vector<int>& w) {
        cum.push_back(w[0]);
        for(int i=1;i<w.size();i++)
        {
            cum.push_back(w[i]+cum.back());
            
        }  
    }
    
    int pickIndex() {
        int index=rand()%(cum.back())+1;
        int s=0;
        int e=cum.size()-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(cum[mid]==index)
            {
                return mid;
                
            }
            else if(cum[mid]<index)
            {
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return s;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
