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
const int N=1000007;

int s[N],p[N],nextt[N];
int n,m;

void getnext()
{
    int i=0,j=-1;
    nextt[0]=-1;
    while(i<m)
    {
        if(j==-1||p[i]==p[j])
        {
            i++;
            j++;
            if(p[i]!=p[j])
                nextt[i]=j;
            else
                nextt[i]=nextt[j];
        }
        else
            j=nextt[j];
    }
}

int solve()
{
    int i=0,j=0;
    while(i<n)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=nextt[j];
        if(j==m)
            return i-m+1;
    }
    return -1;
}

int main()
{
    int T;scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",s+i);
        for(int j=0;j<m;j++) scanf("%d",p+j);
        getnext();
        printf("%d\n",solve());
    }
    return 0;
}
