#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int>&b)
{
	return a.first<b.first;
}
int main() {
	
		int n;
		cin>>n;
		vector<pair<int,int>> a;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			a.push_back({x,y});
		}
		int d,f;
		cin>>d>>f;
		for(int i=0;i<n;i++)
		{
			a[i].first=d-a[i].first;
		}
		sort(a.begin(),a.end(),cmp);
		int i=0;
		int prev=0;
		priority_queue<int> pq;
		int flag=0;
		int ans=0;
		while(i<n)
		{
			if(f>=a[i].first-prev)
			{
				pq.push(a[i].second);
				f=f-(a[i].first-prev);
				prev=a[i].first;
			}
			else
			{
				if(pq.empty())
				{
					flag=1;
					break;
				}
				f+=pq.top();
				pq.pop();
				ans++;
				continue;
			}
			i++;

		}
		if(flag==1)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(d-prev<=f)
		{
			cout<<ans<<endl;
			return 0;
		}
		while(d-prev>f)
		{
			if(pq.empty())
			{
				cout<<-1<<endl;
				return 0;
			}
			f+=pq.top();
			pq.pop();
			ans++;

		}
		cout<<ans<<endl;
		

	
	return 0;
}
