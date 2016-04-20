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

char ss[N];
int s[N];
int c[10];
int lowbit(int x)
{
    return x&(-x);
}

void modify(int x,int v)
{
    for(int i=x;i<=3;i+=lowbit(i))
    {
        c[i]+=v;
    }
}

int sum(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        ans+=c[i];
    }
    return ans;
}

int solve(int *s,int len)
{
    mem(c,0);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        ans+=sum(3)-sum(s[i]);
        modify(s[i],1);
    }
    return ans;
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",ss);
        int len=strlen(ss);
        int minn=INF;
        int tmp;
        for(int i=0;i<len;i++)
        {
            if(ss[i]=='b') s[i]=1;
            else if(ss[i]=='g') s[i]=2;
            else s[i]=3;
        }
        tmp=solve(s,len);
        minn=min(minn,tmp);
        for(int i=0;i<len;i++)
        {
            if(ss[i]=='b') s[i]=3;
            else if(ss[i]=='g') s[i]=2;
            else s[i]=1;

        }
        tmp=solve(s,len);
        minn=min(minn,tmp);
        for(int i=0;i<len;i++)
        {
            if(ss[i]=='b') s[i]=1;
            else if(ss[i]=='g') s[i]=3;
            else s[i]=2;

        }
        tmp=solve(s,len);
        minn=min(minn,tmp);
        for(int i=0;i<len;i++)
        {
            if(ss[i]=='b') s[i]=2;
            else if(ss[i]=='g') s[i]=3;
            else s[i]=1;
        }
        tmp=solve(s,len);
        minn=min(minn,tmp);
        for(int i=0;i<len;i++)
        {
            if(ss[i]=='b') s[i]=2;
            else if(ss[i]=='g') s[i]=1;
            else s[i]=3;

        }
        tmp=solve(s,len);
        minn=min(minn,tmp);
        for(int i=0;i<len;i++)
        {
            if(ss[i]=='b') s[i]=3;
            else if(ss[i]=='g') s[i]=1;
            else s[i]=2;

        }
        tmp=solve(s,len);
        minn=min(minn,tmp);
        printf("%d\n",minn);

    }
    return 0;
}
