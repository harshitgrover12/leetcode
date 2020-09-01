class Solution {
public:
    int Search(int j,vector<int> A)
    {
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==j)
                return i;
        }
        return -1;
    }
    void flip(int k,vector<int> &A)
    {
        for(int i=0;i<(k+1)/2;i++)
        {
            int c=A[i];
            A[i]=A[k-i];
            A[k-i]=c;
            
            }
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        for(int i=A.size();i>=1;i--)
        {
          int ind=Search(i,A);
            if(ind+1==A[ind])
                continue;
            else
            {
                int no=A[ind];
                if(ind!=0)
                ans.push_back(ind+1);
                flip(ind,A);
                ans.push_back(no);
                flip(no-1,A);
            }
           
            
        }
return ans;
        
    }
};
