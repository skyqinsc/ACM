/* rush->AC */
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
using namespace std;

typedef long long LL;
const int N=100007;

struct Seg{
    int col;
    int left,right;
    bool operator <(Seg t) const
    {
        return left<t.left;
    }
}S[N<<2];

vector<Seg> p;
map<int,int> vis;

void push_down(int rt)
{
    if(S[rt].col!=-1)
    {
        S[rt<<1].col=S[rt<<1|1].col=S[rt].col;
        S[rt].col=-1;
    }
}


void build(int rt,int l,int r)
{
    S[rt].col=-1;
    S[rt].left=l;
    S[rt].right=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}

void update(int rt,int l,int r,int col)
{
    //cout<<rt<<endl;
    if(S[rt].left==l&&S[rt].right==r)
    {
        S[rt].col=col;
        return;
    }
    push_down(rt);
    int mid=(S[rt].left+S[rt].right)>>1;
    if(r<=mid) update(rt<<1,l,r,col);
    else if(l>mid) update(rt<<1|1,l,r,col);
    else{
        update(rt<<1,l,mid,col);
        update(rt<<1|1,mid+1,r,col);
    }
    if(S[rt<<1].col==S[rt<<1|1].col&&S[rt<<1].col!=-1)
    {
        S[rt].col=S[rt<<1].col;
    }
}

void query(int rt)
{
    //cout<<rt<<": "<<S[rt].col<<endl;
    if(S[rt].col!=-1)
    {
        p.push_back(S[rt]);
        return;
    }
    if(S[rt].left==S[rt].right) return;
    query(rt<<1);
    query(rt<<1|1);
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vis.clear();p.clear();
        int l,r,c;
        build(1,1,10000);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&l,&r,&c);
            update(1,l+1,r,c);

        }
        query(1);
        sort(p.begin(),p.end());
        vis[p[0].col]++;
        for(int i=1;i<p.size();i++)
        {
            if(p[i].col==p[i-1].col&&p[i].left-1<=p[i-1].right)
                ;
            else
                vis[p[i].col]++;
        }
        map<int,int>::iterator it;
        for(it=vis.begin();it!=vis.end();it++)
        {
            printf("%d %d\n",(*it).first,(*it).second);
        }
        printf("\n");
    }
    return 0;
}
