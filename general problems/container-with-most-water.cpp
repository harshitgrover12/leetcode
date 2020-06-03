class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        int left=0;
        int right=n-1;
        int max_area=0;
        while(left<right)
        {
            int mini=min(a[left],a[right]);
            max_area=max(max_area,mini*(right-left));
            if(a[left]<a[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};
