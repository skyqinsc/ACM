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
#define mod 999101
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;
const int N=100007;

LL qpow(LL a,LL b,LL p)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

LL C(LL n,LL m,LL p)
{
    if(n>m) return 0;
    if(m-n<m) m=m-n;
    LL s1=1,s2=1;
    for(int i=0;i<m;i++)
    {
        s1=(s1*(n-i))%p;
        s2=(s2*(i+1))%p;
    }
    return s1*qpw(s2,p-2,p)%p;
}

LL lucas(LL n,LL m)
{
    if(!n) return 1;
    return C(n%p,m%p,p)*lucas(n/p,m/p,p);
}


int main()
{
    LL n;
    while(scanf("%I64d",&n)==1)
    {
        for(int i=)
    }
    return 0;
}
