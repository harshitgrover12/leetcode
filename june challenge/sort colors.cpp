class Solution {
public:
    void swap(int *a,int *b){
        int c=*a;
        *a=*b;
        *b=c;
    }
    void sortColors(vector<int>& a) {
        int s=0;
        int mid=0;
        int e=a.size()-1;
       for(int i=0;i<a.size();i++)
        {
            if(a[mid]==1)
                mid++;
            else if(a[mid]==2)
            {
                swap(&a[mid],&a[e]);
                
                e--;
            }
            else
            {
                swap(&a[mid],&a[s]);
                mid++;
                s++;
            }
            
        }
        
    }
};
