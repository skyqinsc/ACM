/* 
*    Algorithm: 离线LCA
*         Date: 2015-08-26
*      Contest: 练习
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define INF 1<<29
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL;
const int N=100007;

struct Adj{
    int to,w;
    int nxt;
}E[2][N];

int tot[2];
int head[2][N];
int dist[N],vis[N];
int uset[N];

void add_edge(int u,int v,int w,int kind)
{
    E[kind][tot[kind]].to=v;
    E[kind][tot[kind]].w=w;
    E[kind][tot[kind]].nxt=head[kind][u];
    head[kind][u]=tot[kind]++;
}

int find_set(int x)
{
    if(uset[x]!=x)
    {
        uset[x]=find_set(uset[x]);
    }
    return uset[x];
}

void union_set(int x,int y)
{
    int fx,fy;
    fx=find_set(x);
    fy=find_set(y);
    if(fx==fy) return;
    else
        uset[fx]=fy;
}

void tarjan(int u)
{
    uset[u]=u;
    vis[u]=0;
    for(int i=head[0][u];i!=-1;i=E[0][i].nxt)
    {
        int v=E[0][i].to;
        if(vis[v]==-1)
        {
            dist[v]=dist[u]+E[0][i].w;
            tarjan(v);
            uset[v]=u;
        }
    }
    vis[u]=1;
    for(int i=head[1][u];i!=-1;i=E[1][i].nxt)
    {
        int v=E[1][i].to;
        if(vis[v]==1)
        {
            E[1][i].w=dist[u]+dist[v]-2*dist[find_set(v)];
        }
    }
}

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        tot[0]=tot[1]=0;
        mem(head,-1);
        mem(vis,-1);
        int u,v,k;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&k);
            add_edge(u,v,k,0);
            add_edge(v,u,k,0);
        }

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v,0,1);
            add_edge(v,u,0,1);
        }
        dist[1]=0;
        tarjan(1);
        for(int i=0;i<tot[1];i++)
        {
            if(E[1][i].w)
            printf("%d\n",E[1][i].w);
        }

    }
    return 0;
}
