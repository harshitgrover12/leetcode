class Solution {
public:
    vector<int> final_ans;
    void helper(int x,int n,int k, vector<int> ans)
    {
        if(x==n)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum=sum*10+ans[i];
            }
            final_ans.push_back(sum);
            return;
        }
        for(int i=0;i<=9;i++)
        {
            if(ans.size()==0 &&i==0)
                continue;
            
                if(ans.size()==0||abs(i-ans[ans.size()-1])==k)
                {
                ans.push_back(i);
                    helper(x+1,n,k,ans);
                    ans.pop_back();
                }
                
            }
        }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        helper(0,n,k,ans);
        return final_ans;
        
    }
};
