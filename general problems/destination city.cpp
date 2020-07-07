class Solution {
public:
    map<string,vector<string>> mp;
    string destCity(vector<vector<string>>& paths) {
        
        for(auto it:paths)
        {
            mp[it[0]].push_back(it[1]);
        }
        
        queue<string> q;
        for(auto it:mp)
        {
            for(auto i:mp[it.first])
            {
                if(mp[i].size()==0)
                    return i;
            }
        }
        return "";
        
    }
};
