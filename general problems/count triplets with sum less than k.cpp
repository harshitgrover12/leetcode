#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,x;
	    cin>>n>>x;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    sort(a.begin(),a.end());
	    int cnt=0;
	    for(int i=0;i<n-2;i++)
	    {
	        int j=i+1;
	        int k=n-1;
	        while(j<k)
	        {
	            if(a[i]+a[j]+a[k]>=x)
	            {
	                k--;
	            }
	            else
	            {
	            cnt+=(k-j);
	            j++;
	            }
	        }
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
