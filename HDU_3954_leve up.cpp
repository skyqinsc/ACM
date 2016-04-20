//author:ACsorry
//result:Yes
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
#define maxInt 0x7fffffff
#define SUP 0x80000000
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;
const int N=50007;

struct Node{
    int exp,level,min_dist,lazy;
    int left,right,mid;
}L[N<<2];
int n,k,qw;
int needk[20];

void build(int rt,int l,int r)
{
    L[rt].exp=L[rt].lazy=0;
    L[rt].min_dist=needk[1];
    L[rt].level=1;
    L[rt].left=l;
    L[rt].mid=(l+r)>>1;
    L[rt].right=r;
    if(l==r) return;
    build(rt<<1,l,L[rt].mid);
    build(rt<<1|1,L[rt].mid+1,r);
}

void push_down(int rt)
{
    if(L[rt].lazy)
    {
        L[rt<<1].lazy+=L[rt].lazy;
        L[rt<<1].min_dist-=L[rt].lazy;
        L[rt<<1].exp+=L[rt<<1].level*L[rt].lazy;

        L[rt<<1|1].lazy+=L[rt].lazy;
        L[rt<<1|1].min_dist-=L[rt].lazy;
        L[rt<<1|1].exp+=L[rt<<1|1].level*L[rt].lazy;

        L[rt].lazy=0;
    }
}

void push_up(int rt)
{
    L[rt].exp=max(L[rt<<1].exp,L[rt<<1|1].exp);
    L[rt].level=max(L[rt<<1].level,L[rt<<1|1].level);
    L[rt].min_dist=min(L[rt<<1].min_dist,L[rt<<1|1].min_dist);
}



void update(int rt,int l,int r,int e)
{

    if(L[rt].left==L[rt].right)
    {
        L[rt].exp+=L[rt].level*e;
        while(L[rt].exp>=needk[L[rt].level])
            L[rt].level++;
        L[rt].min_dist=(needk[L[rt].level]-L[rt].exp)/L[rt].level+((needk[L[rt].level]-L[rt].exp)%L[rt].level!=0);
        return;
    }
    if(l==L[rt].left&&L[rt].right==r)
    {
        if(L[rt].min_dist<=e)
        {
            push_down(rt);
            update(rt<<1,l,L[rt].mid,e);
            update(rt<<1|1,L[rt].mid+1,r,e);
            push_up(rt);
        }
        else
        {
            L[rt].exp+=L[rt].level*e;
            L[rt].lazy+=e;
            L[rt].min_dist-=e;
        }
        return;
    }
    push_down(rt);
    if(r<=L[rt].mid) update(rt<<1,l,r,e);
    else if(l>L[rt].mid) update(rt<<1|1,l,r,e);
    else{
        update(rt<<1,l,L[rt].mid,e);
        update(rt<<1|1,L[rt].mid+1,r,e);
    }
    push_up(rt);
}


int query(int rt,int l,int r)
{
    if(l==L[rt].left&&L[rt].right==r)
    {
        return L[rt].exp;
    }
    push_down(rt);
    if(r<=L[rt].mid) return query(rt<<1,l,r);
    else if(l>L[rt].mid) return query(rt<<1|1,l,r);
    else{
        return max(query(rt<<1,l,L[rt].mid),query(rt<<1|1,L[rt].mid+1,r));
    }
}
int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&qw);
        for(int i=1;i<k;i++) scanf("%d",&needk[i]);
        needk[k]=1<<30;
        char ch[10];
        int a,b,c;
        build(1,1,n);
        printf("Case %d:\n",++cas);
        for(int i=0;i<qw;i++)
        {
            scanf("%s",ch);
            if(ch[0]=='W')
            {
                scanf("%d%d%d",&a,&b,&c);
                update(1,a,b,c);
            }
            else
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,a,b));
            }
        }
        printf("\n");
    }
    return 0;
}
