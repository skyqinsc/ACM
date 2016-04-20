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

int dig[2][10];
LL dp[10][10][2],id;

void mod10(int iid,LL n)
{
    int id=1;
    while(n)
    {
        dig[iid][id++]=n%10;
        n/=10;
    }
    dig[iid][0]=id-1;
}

LL dfs(int pos,int pre,int en,int limit)
{
    if(pos==-1) return en;
    if(!limit&&dp[pos][pre][en]!=-1)
        return dp[pos][pre][en];

    int last=limit?dig[id][pos]:9;
    LL ret=0;
    for(int i=0;i<=last;i++)
        ret+=dfs(pos-1,i,en||(pre==6&&i==2)||i==4,limit&&(i==last));
    if(!limit)
        dp[pos][pre][en]=ret;
    return ret;
}

int main()
{
    LL n,m;
    while(scanf("%I64d%I64d",&n,&m)==2,n+m)
    {
        LL nn,mm;
        mem(dp,-1);
        mod10(0,--n);
        mod10(1,m);
        id=0;
        nn=dfs(dig[id][0],0,0,1);
        id=1;
        mm=dfs(dig[id][0],0,0,1);

        printf("%I64d\n",LL(m-n)-(mm-nn));

    }
    return 0;
}
