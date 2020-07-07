class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        map<char,int> mp1;
        for(int i=0;i<magazine.length();i++)
            mp[magazine[i]]++;
        for(int i=0;i<ransomNote.length();i++)
            mp1[ransomNote[i]]++;
        for(auto it:mp1)
        {
            if(mp[it.first]<it.second)
                return false;
        }
        return true;
        
    }
};
