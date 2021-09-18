#include "testlib.h"
#include<bits/stdc++.h>
//#define int long long
#define matsuri pair<int,int>
using namespace std; 
const int iris = 1e9+7;

int dd[1000010],cnt[1000010]={1};
int id[1000010];
int ff[1000010],akari[1000010];

signed main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	registerGen(argc, argv, 1);
	
	int n,q,i,a,b,s,l,r,c,d,j,ss,aoi;
	double meow,meowmeow;
	
	s=atoi(argv[1]);
	meow=atof(argv[2]);
	meowmeow=atof(argv[3]);
	
	if(s==0)
	{
		n=5;
		q=5;
	}
	else if(s==1)
	{
		n=rnd.next(1,5000);
		q=rnd.next(1,5000);
		//meow=0.01;
	}
	else if(s==2)
	{
		n=rnd.wnext(100000,5)+1;
		q=rnd.wnext(100000,5)+1;
		//meow=0.005;
	}
	else if(s==3)
	{
		n=rnd.wnext(1000000,30)+1;
		q=rnd.wnext(1000000,30)+1;
		//meow=0.005;
	}
	else if(s==4)
	{
		n=rnd.wnext(100000,5)+1;
		q=rnd.wnext(100000,5)+1;
		//meow=0.1;
	}
	else if(s==5)
	{
		n=rnd.wnext(100000,40)+1;
		q=rnd.wnext(100000,40)+1;
		//meow=0.005;
	}
	else if(s==6)
	{
		n=rnd.wnext(1000000,30)+1;
		q=rnd.wnext(1000000,30)+1;
		//meow=0.005;
	}
	
	cout<<n<<'\n';
	
	for(i=1;i<=n;i++)
	{
		id[i]=i;
	}
	//shuffle(id+1,id+n+1);
	
	for(i=2;i<=n;i++)
	{
		if(i<=n/10)
			a=rnd.wnext(i-1,i*meowmeow)+1;
		else
			a=rnd.wnext(i-1,i*meow)+1;
		
		cout<<a<<' '<<i<<'\n';
		ff[i]=a;
		
		dd[i]=dd[a]+1;
		cnt[dd[i]]++;
	}
	for(i=n;i;i--)
	{
		akari[i]=max(akari[i], 1);
		akari[ff[i]]=max(akari[ff[i]], akari[i]+1);
	}
	cout<<q<<'\n';
	
	aoi=rnd.next(akari[1]/2,akari[1]);
	for(i=1;q && i<=n;i++)
	{
		if(s==2)
		{
			for(j=0;j<=100 && q;j++)
			{
				cout<<i<<' '<<j<<'\n';
				q--;
			}
		}
		else if(s==3)
		{
			cout<<i<<' '<<aoi<<'\n';
			q--;
		}
		else
		{
			for(j=1;q && j<=100 && akari[i]-j>=0;j++)
			{
				cout<<i<<' '<<akari[i]-j<<'\n';
				q--;
			}
		}
	}
	while(q--)
	{
		if(s==2)
			cout<<rnd.next(1,n)<<' '<<rnd.next(0,100)<<'\n';
		else if(s==3)
			cout<<rnd.next(1,n)<<' '<<aoi<<'\n';
		else
			cout<<rnd.next(1,n)<<' '<<rnd.next(0,n)<<'\n';
	}
	
	return 0;
}
