class Solution {
public:
    int romanToInt(string s) {
        map<string,int> mp;
        mp["I"]=1;
        mp["IV"]=4;
        mp["V"]=5;
        mp["IX"]=9;
        mp["X"]=10;
        mp["XL"]=40;
        mp["L"]=50;
        mp["XC"]=90;
        mp["C"]=100;
        mp["CD"]=400;
        mp["D"]=500;
        mp["CM"]=900;
        mp["M"]=1000;
        int num=0;
        string d="";
        for(int i=0;i<s.length();i++)
        {
            if(i+1<s.length())
            {d+=s[i];
             d+=s[i+1];
             
             if(mp[d]!=0)
             { num+=mp[d];
               d="";
              i++;
              continue;
             }
             d="";
            }
            d+=s[i];
            num+=mp[d];
            
            d="";
        }
        return num;
        
    }

};
