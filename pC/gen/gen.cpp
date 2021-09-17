#include "testlib.h"
#include<bits/stdc++.h>
//#define int long long
#define matsuri pair<int,int>
using namespace std; 
const int iris = 1e9+7;

bool check(int a,int b,int c,int d,int e,int f)
{
	int aa,bb,cc,dd;
	aa=min(a,c);
	bb=min(b,d);
	cc=max(a,c);
	dd=max(b,d);
	return aa<=e && e<=cc && bb<=f && f<=dd;
}

signed main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	registerGen(argc, argv, 1);
	
	int n,m,a,b,c,d,e,f,i,j,aoi;
	int s,ss;
	s=atoi(argv[1]);
	ss=atoi(argv[2]);
	
	if(s==3)
	{
		n=m=4;
	}
	else
	{
		n=rnd.wnext(1000,10)+1;
		m=rnd.wnext(1000,10)+1;
	}
	cout<<n<<' '<<m<<'\n';
	
	a=rnd.next(1,n);
	b=rnd.next(1,m);
	do
	{
		c=rnd.next(1,n);
		d=rnd.next(1,m);
	}
	while(a==c && b==d);
	if(s==2 || s==4)
	{
		do
		{
			e=rnd.next(1,n);
			f=rnd.next(1,m);
		}
		while((a==e && b==f) || (c==e && d==f) || ((check(a,b,c,d,e,f)^(ss<=4))));
	}
	else
	{
		do
		{
			e=rnd.next(1,n);
			f=rnd.next(1,m);
		}
		while((a==e && b==f) || (c==e && d==f));
	}
	cout<<a<<' '<<b<<'\n'<<c<<' '<<d<<'\n';
	
	if(s==1)
		e=f=-1;
	if(s==2)
		aoi=rnd.next(0,1000000000);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s==2)
				a=aoi;
			else
				a=rnd.next(0,1000000000);
			if(i==e && j==f)
			{
				a=rnd.next(0,1000000000);
				if(s==2)
				{
					a=min(a, aoi-1);
				}
				a=-a;
			}
			cout<<a<<" \n"[j==m];
		}
	}
	
	
	return 0;
}
