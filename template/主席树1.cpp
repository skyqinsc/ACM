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

struct node{
    int ls,rs;
    int sum,w;
}p[N*20];
int root[N],tot;
int a[N],b[N];

int build(int l,int r)
{
    int rt=tot++;
    p[rt].w=p[rt].sum=0;

    if(l==r) return rt;
    int m=l+t>>1;
    p[rt].ls=build(l,m);
    p[rt].rs=build(m+1,r);
    return rt;
}

int modify(int x,int v,int i,int l,int r)
{
    int rt=tot++;
    p[rt]=p[i];
    if(l==r){
        p[rt].w++;
        p[rt].sum+=v;
        return rt;
    int m=l+r>>1;
    if(x<=m) p[rt].ls=modify(x,v,p[i].ls,l,m);
    else p[rt].rs=modify(x,v,p[i].rs,m+1,r);
    return rt;
}

int query(int )


int main()
{

    return 0;
}
