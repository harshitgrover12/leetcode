class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int cnt=1;
        while(candies>0)
        {
            
            for(int i=0;i<num_people;i++)
            {
                
                if(candies-cnt<=0)
                {
                    cnt=candies;
                    candies=0;
                }
                else
                    candies=candies-cnt;
                ans[i]+=cnt;
                if(candies==0)
                    break;
                
               
                cnt++;     
            }
        }
        return ans;
        
    }
};
