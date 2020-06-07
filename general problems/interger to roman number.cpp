class Solution {
public:
    int binarysearch(int a[],int no,int n)
    {
        int s=0;
        int e=n-1;
        while(s<=e)
              {
            int mid=(s+e)/2;
            if(a[mid]==no)
                return mid;
            else if(a[mid]<no)
                s=mid+1;
            else if(a[mid]>no)
                e=mid-1;

              }
        return a[s-1];
    }
    string intToRoman(int num) {
        int d=num;
        int c=0;
        while(d!=0)
        {
            c++;
            d/=10;
        }
        map<int,string> mp;
        mp[1]="I";
        mp[4]="IV";
        mp[5]="V";
        mp[9]="IX";
        mp[10]="X";
        mp[40]="XL";
        mp[50]="L";
        mp[90]="XC";
        mp[100]="C";
        mp[400]="CD";
        mp[500]="D";
        mp[900]="CM";
        mp[1000]="M";
        int a[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        
        string ans="";
        while(c!=0)
        {
            int n=pow(10,c-1);
            int r=num/n;
            
            int no=n*r;
            
            if(no==0)
            {
                c--;
                num=num%n;
                continue;
            }
            
            if(mp[no]=="")
            {
                int f=binarysearch(a,no,13);
                ans+=mp[f];
                int rem=(no-f);
                int rep=rem/n;
                while(rep!=0)
                {
                    ans+=mp[n]; 
                    rep--;
                }
                
            }
            else
                ans+=mp[no];
            c--;
            num=num%n;
            
        }
        return ans;
    }
};
