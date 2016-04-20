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
    LL sum;
    int left,right;
    LL lazy;
}S[N<<2];

void push_down(int rt)
{
    if(S[rt].lazy)
    {
        S[rt<<1].sum+=(S[rt<<1].right-S[rt<<1].left+1)*S[rt].lazy;
        S[rt<<1].lazy+=S[rt].lazy;
        S[rt<<1|1].sum+=(S[rt<<1|1].right-S[rt<<1|1].left+1)*S[rt].lazy;
        S[rt<<1|1].lazy+=S[rt].lazy;

        S[rt].lazy=0;
    }
}

void push_up(int rt)
{
    S[rt].sum=S[rt<<1].sum+S[rt<<1|1].sum;
}

void build(int rt,int l,int r)
{
    S[rt].left=l;
    S[rt].right=r;
    S[rt].lazy=0;
    int mid=(l+r)>>1;
    if(S[rt].left==S[rt].right)
    {
        scanf("%I64d",&S[rt].sum);
        return;
    }
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}



void update(int rt,int l,int r,LL c)
{
    if(S[rt].left==l&&S[rt].right==r)
    {
        S[rt].sum+=(r-l+1)*c;
        S[rt].lazy+=c;
        return;
    }
    push_down(rt);
    int mid=(S[rt].right+S[rt].left)>>1;
    if(r<=mid) update(rt<<1,l,r,c);
    else if(l>mid) update(rt<<1|1,l,r,c);
    else{
        update(rt<<1,l,mid,c);
        update(rt<<1|1,mid+1,r,c);
    }
    push_up(rt);
}

LL query(int rt,int l,int r)
{
    if(S[rt].left==l&&S[rt].right==r)
    {
        return S[rt].sum;
    }
    push_down(rt);
    LL ret=0;
    int mid=(S[rt].right+S[rt].left)>>1;
    if(r<=mid) ret+=query(rt<<1,l,r);
    else if(l>mid) ret+=query(rt<<1|1,l,r);
    else{
        ret+=query(rt<<1,l,mid);
        ret+=query(rt<<1|1,mid+1,r);
    }
    push_up(rt);
    return ret;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        build(1,1,n);
        char ch[10];
        int a,b;
        LL c;
        for(int i=0;i<m;i++)
        {
            scanf("%s",ch);
            if(ch[0]=='Q'){
                scanf("%d%d",&a,&b);
                printf("%I64d\n",query(1,a,b));
            }
            else{
                scanf("%d%d%I64d",&a,&b,&c);
                update(1,a,b,c);
            }
        }
    }
    return 0;
}
