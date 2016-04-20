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
#define INF 0x7fffffff
#define SUP 0x80000000
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;
const int N=100007;
struct Tree{
    int ls,rs;
    int w;
}p[N*20];
int tot;
LL a[N],b[N];
int root[N];

int build(int l,int r)
{
    int rt=tot++;
    p[rt].w=0;
    if(l==r) return rt;
    int m=(l+r)>>1;
    p[rt].ls=build(l,m);
    p[rt].rs=build(m+1,r);
    return rt;
}

int modify(int x,int v,int i,int l,int r)
{
    int rt=tot++;
    p[rt]=p[i];
    p[rt].w+=v;
    if(l==r) return rt;
    int m=(l+r)>>1;
    if(x<=m) p[rt].ls=modify(x,v,p[i].ls,l,m);
    else p[rt].rs=modify(x,v,p[i].rs,m+1,r);
    return rt;
}

int query(int i,int j,int h,int l,int r)
{
    if(l==r) return p[i].w-p[j].w;
    int ret=0;
    int m=(l+r)>>1;
    if(h>m){
        ret+=(p[p[i].ls].w-p[p[j].ls].w);
        ret+=query(p[i].rs,p[j].rs,h,m+1,r);
    }
    else
        ret+=query(p[i].ls,p[j].ls,h,l,m);
    return ret;
}

int main()
{
    int T,cas=0;scanf("%d",&T);
    int n,m;
    while(T--)
    {
        tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%I64d",a+i);
            b[i]=a[i];
        }
        sort(b+1,b+1+n);
        int tmp=unique(b+1,b+1+n)-(b+1);
        tmp++;
        b[tmp]=INF;
        root[0]=build(1,tmp);
        for(int i=1;i<=n;i++){
            int mp=lower_bound(b+1,b+1+tmp,a[i])-b;
            root[i]=modify(mp,1,root[i-1],1,tmp);
        }
        printf("Case %d:\n",++cas);
        int L,R;
        LL H;
        while(m--){

            scanf("%d%d%I64d",&L,&R,&H);
            L++;R++;
            int mp=upper_bound(b+1,b+1+tmp,H)-b-1;
            if(mp>0)
                printf("%d\n",query(root[R],root[L-1],mp,1,tmp));
            else
                printf("0\n");
        }
    }

    return 0;
}
