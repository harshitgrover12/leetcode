class Solution {
public:
    int titleToNumber(string s) {
        int cnt=0;
        int sum=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            sum=sum+pow(26,cnt)*(s[i]-'A'+1);
            cnt++;
        }
        return sum;
        
    }
};
