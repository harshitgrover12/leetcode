class ProductOfNumbers {
public:
    vector<int> a;
    vector<int> dp;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
        {
            dp.clear();
            a.push_back(num);
            return;
        }
        a.push_back(num);
        if(dp.size()==0)
            dp.push_back(num);
        else
            dp.push_back(dp[dp.size()-1]*num);
            
        
    }
    
    int getProduct(int k) {
        if(dp.size()==0||k>dp.size())
            return 0;
        else
        {
            if(k==dp.size())
                return dp[dp.size()-1];
            return dp[dp.size()-1]/dp[dp.size()-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
