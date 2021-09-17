#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
using namespace std; 
const int iris = 998244353;

int arr[1010][1010],dis[3][1010][1010],aoi[1010][1010];
int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
#define sagiri pair<int,matsuri>
priority_queue<sagiri, vector<sagiri>, greater<sagiri> > pq;

void dijk(int a,int b,int k)
{
	int i,j,c,d;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dis[k][i][j]=1e18;
		}
	}
	dis[k][a][b]=arr[a][b];
	pq.push({dis[k][a][b], {a,b}});
	while(!pq.empty())
	{
		a=pq.top().second.first;
		b=pq.top().second.second;
		c=pq.top().first;
		pq.pop();
		if(dis[k][a][b]!=c)
		{
			continue;
		}
		for(i=0;i<4;i++)
		{
			c=a+dir[i][0];
			d=b+dir[i][1];
			if(c<1 || c>n || d<1 || d>m)
			{
				continue;
			}
			if(dis[k][a][b]+arr[c][d]<dis[k][c][d])
			{
				dis[k][c][d]=dis[k][a][b]+arr[c][d];
				pq.push({dis[k][c][d], {c,d}});
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j,ans=1e18,akari,x,y,ex,ey,sx,sy,nene;
	akari=0;
	x=y=1;
	
	cin>>n>>m;
	cin>>sx>>sy;
	cin>>ex>>ey;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]<0)
			{
				akari=arr[i][j];
				arr[i][j]=0;
				x=i;
				y=j;
			}
		}
	}
	dijk(sx,sy,0);
	dijk(x,y,1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			aoi[i][j]=arr[i][j]+max(0LL, arr[i][j]+akari);
			arr[i][j]=max(0LL, arr[i][j]+akari);
		}
	}
	dijk(ex,ey,2);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			nene=dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-aoi[i][j];
			if(nene<=ans)
			{
				ans=nene;
			}
		}
	}
	ans=min(ans, dis[0][ex][ey]);
	cout<<ans<<'\n';
	
	return 0;
}
