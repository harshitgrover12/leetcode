class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
    int s=0;
        int e=A.size()-1;
        vector<int> ans(e+1);
        for(int i=0;i<A.size();i++)
        {
            
            if(A[i]%2==0)
                ans[s++]=A[i];
            else
                ans[e--]=A[i];
            
        }
        return ans;
        
    }
};
