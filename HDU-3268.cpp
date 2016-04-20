/* 
*    Algorithm: SPFA
*         Date: 2015-08-26
*      Contest: WUST2015暑假训练赛14（2015-8-25）
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=1000;
int price[N];

struct Adj{
	int to,next;
	int w;
}adj[N];
int tot_,head[N];
void add(int u,int v,int w)
{
	adj[tot_].to=v;
	adj[tot_].w=w;
	adj[tot_].next=head[u];
	head[u]=tot_++;
}
int vis[N];
void spfa(int n)
{
	memset(vis,0,sizeof vis);
	queue<int> que;
	for(int i=1;i<=n;i++) que.push(i);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=0;
		for(int i=head[u];~i;i=adj[i].next)
		{
			int v=adj[i].to;
			if(price[v]>price[u]+adj[i].w)
			{
				//cout<<v<<"-----"<<endl;
				//getchar();
				price[v]=price[u]+adj[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
}

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(head,-1,sizeof head);tot_=0;
		int n;scanf("%d",&n);
		int a,b,c;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			price[a]=b-1;
		}
		int m;scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(price[i]==price[j])
					add(i,j,0),add(j,i,0);
		spfa(n);
		for(int i=1;i<=n;i++)
            printf("%d %d\n",i,price[i]);
        int ans=0;
        for(int k=1;k<=n;k++)
        {
			int flag=1;
            for(int i=1;flag&&i<=n;i++)
            for(int j=i+1;flag&&j<=n;j++)
                if(i!=j&&i!=k&&j!=k&&price[k]==price[i]+price[j])
					ans++,flag=0;
        }
        printf("%d\n",ans);
	}
	return 0;
}
