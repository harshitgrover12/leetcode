class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<matrix.size();i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]<mini)
                    mini=matrix[i][j];
            }
            
            mp[mini]=1;
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            int maxi=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            
            if(matrix[i][j]>maxi)
                maxi=matrix[i][j];
        }
            if(mp[maxi])
                ans.push_back(maxi);
            
            
        }
        return ans;
        
    }
};
