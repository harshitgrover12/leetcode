#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int>&b)
{
	return a.second<b.second;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int>> a;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			a.push_back({x,y});
		}
		sort(a.begin(),a.end(),cmp);
		int cnt=1;
		int temp=a[0].second;
		for(int i=0;i<n;i++)
		{
				if(a[i].first>=temp)
				{
					cnt++;
					temp=a[i].second;
				}
		}
		cout<<cnt<<endl;

	}
	return 0;
}
