/* 
*    Algorithm: 在线LCA
*         Date: 2015-08-26
*      Contest: 2015 多校(1)
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
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
const int N=100007;

int E[N<<1]; //Euler tour 2*n-1
int L[N<<1]; //the level of the node visited in Euler tour
int H[N]; //the index of the first occurrence of node i int E
int dist[N];
int tag;

struct node{
    int to,len;
    int next;
}gra[N<<1];
int tot_;
int head[N];
void add_edge(int u,int v,int w)
{
    gra[tot_].to=v;
    gra[tot_].len=w;
    gra[tot_].next=head[u];
    head[u]=tot_++;
}

//vector<node> gra[N];
int vis[N],dfn[N],rdfn[N],dfn_;

void dfs(int c,int level)
{
    vis[c]=1;
    L[tag]=level,E[tag]=c,H[c]=tag,dfn[c]=dfn_++;
    tag++;
    for(int i=head[c];i!=-1;i=gra[i].next)
    {
        int to=gra[i].to;
        if(!vis[to])
        {
            dist[to]=dist[c]+gra[i].len;
            dfs(to,level+1);
            L[tag]=level,E[tag]=c;
            tag++;
        }
    }
}

int dp[N<<1][20];
void init_RQM()
{
    for(int i=0;i<tag;i++)
        dp[i][0]=i;
    int m=floor(log(tag-1.0)/log(2.0));
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j+(1<<i)-1<tag;j++)
        {
            int a=dp[j][i-1],b=dp[j+(1<<(i-1))][i-1];
            dp[j][i]=(L[a]<L[b])?a:b;
        }
    }
}

int RQM(int l,int r)
{
    if(l>r) swap(l,r);
    int m=floor(log(r-l+1.0)/log(2.0));
    int a=dp[l][m],b=dp[r-(1<<m)+1][m];
    return L[a]<L[b]?a:b;
}

int LCA(int u,int v)
{
    if(u==v) return u;
    int l=H[u],r=H[v];
    return E[RQM(l,r)];
}


//---------------------

set<int> set_;
int main()
{
    //freopen("1009.in","r",stdin);
    //freopen("1009out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        set_.clear();
        memset(vis,0,sizeof vis);
        memset(head,-1,sizeof head);
        dfn_=1,tot_=0,tag=0;
        int n,m;
        scanf("%d%d",&n,&m);
        int u,v,w;

        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }

        dfs(1,0);
        init_RQM();
        for(int i=1;i<=n;i++)
        {
            //printf("%d ",dfn[i]);
            rdfn[dfn[i]]=i;
        }
        //cout<<"/n--"<<endl;
        init_RQM();
        int op,out=0;
        int x,y;
        printf("Case #%d:\n",++cas);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&op,&u);
            if(op==1)
            {
                if(set_.count(dfn[u])==0)
                {
                    if(set_.size()==0)
                    {
                        set_.insert(dfn[u]);
                        printf("%d\n",out);
                    }
                    else{
                        set<int>::iterator it_max=set_.upper_bound(dfn[u]);
                        if(it_max==set_.end())
                        {
                            x=rdfn[*set_.begin()];
                            y=rdfn[*set_.rbegin()];
                        }
                        else{
                            y=rdfn[*it_max];
                            if(it_max!=set_.begin())
                                x=rdfn[*(--it_max)];
                            else{
                                x=rdfn[*set_.begin()];
                                y=rdfn[*set_.rbegin()];
                            }
                        }
                        set_.insert(dfn[u]);
                        out+=dist[u]-dist[LCA(x,u)]-dist[LCA(y,u)]+dist[LCA(x,y)];
                        printf("%d\n",out);
                    }
                }
                else
                    printf("%d\n",out);

            }
            else
            {
                if(set_.count(dfn[u])!=0)
                {
                    set_.erase(dfn[u]);
                    if(set_.size()==0)
                    {
                        set_.insert(dfn[u]);
                        out=0;
                        printf("%d\n",out);
                    }
                    else{
                        set<int>::iterator it_max=set_.upper_bound(dfn[u]);
                        if(it_max==set_.end())
                        {
                            x=rdfn[*set_.begin()];
                            y=rdfn[*set_.rbegin()];
                        }
                        else{
                            y=rdfn[*it_max];
                            if(it_max!=set_.begin())
                                x=rdfn[*(--it_max)];
                            else{
                                x=rdfn[*set_.begin()];
                                y=rdfn[*set_.rbegin()];
                            }
                        }
                        out-=dist[u]-dist[LCA(x,u)]-dist[LCA(y,u)]+dist[LCA(x,y)];
                    }

                }
                printf("%d\n",out);
            }
        }
    }
    return 0;
}

