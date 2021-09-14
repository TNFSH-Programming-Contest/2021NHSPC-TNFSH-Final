#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
using namespace std; 
const int iris = 998244353;

vector<int> G[1000010];
int dd[1000010],n;
vector<int> aoi[1000010];
vector<matsuri> qq[1000010];
int in[1000010],out[1000010],bit[1000010],k;
int ans[1000010];

void dfs(int a,int f)
{
	in[a]=++k;
	dd[a]=dd[f]+1;
	aoi[dd[a]].emplace_back(a);
	for(int b:G[a])
	{
		if(b==f)
			continue;
		dfs(b,a);
	}
	out[a]=k;
}

void add(int p)
{
	int i;
	for(i=p;i<=n;i+=i&(-i))
	{
		bit[i]++;
	}
}

int qry(int a)
{
	int i,res=0;
	for(i=a;i>0;i-=i&(-i))
	{
		res+=bit[i];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a,b,q,i;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		G[a].emplace_back(b);
	}
	dfs(1,0);
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>a>>b;
		b=min(dd[a]+b, n);
		qq[b].emplace_back(i,a);
	}
	for(i=1;i<=n;i++)
	{
		for(int a:aoi[i])
		{
			add(in[a]);
		}
		for(auto sana:qq[i])
		{
			a=sana.first;
			b=sana.second;
			ans[a]=qry(out[b])-qry(in[b]-1);
		}
	}
	for(i=1;i<=q;i++)
	{
		cout<<ans[i]<<'\n';
	}
	
	return 0;
}
