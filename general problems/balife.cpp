#include<bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin>>n;
	vector<int> a(n);
	int total=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];total+=a[i];
	}
	if(total%n!=0)
	{
	cout<<-1<<endl;
	return 0;
	}
	int t=total/n;
	int sum=0;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		maxi=max(abs(sum-(t*(i+1))),maxi);
	}
	cout<<maxi<<endl;
	return 0;
}
