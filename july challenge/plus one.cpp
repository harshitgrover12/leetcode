class Solution {
public:
    vector<int> plusOne(vector<int>& digit) {
        int carry=1;
        for(int j=digit.size()-1;j>=0;j--)
        {
            digit[j]+=carry;
            carry=digit[j]/10;
            digit[j]=digit[j]%10;
            
        }
        if(carry)
            digit.insert(digit.begin(),carry);
    
        return digit;
    }
};
