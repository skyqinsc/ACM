//problem:   zoj 2107 Quoit Design
//author:    ACsorry
//result:    Yes

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
const int N=100007;

struct Point{
    double x,y;
}p[N];
int tmp[N];


double dis(int a,int b)
{
    return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}

int cmpxy(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int cmpy(int a,int b)
{
    return p[a].y<p[b].y;
}

double closestPair(int L,int R)
{
    double ret=1e20;
    if(L==R) return ret;
    if(L+1==R)
        return dis(L,R);
    int mid=(L+R)>>1;

    ret=min(closestPair(L,mid),closestPair(mid+1,R));
    int cnt=0;
    for(int i=L;i<=R;i++){
        if(fabs(p[i].x-p[mid].x)<=ret)
            tmp[cnt++]=i;
    }
    sort(tmp,tmp+cnt,cmpy);

    for(int i=0;i<cnt;i++)
    {
        for(int j=i+1;j<cnt&&p[tmp[j]].y-p[tmp[i]].y<ret;j++)
        {
            ret=min(ret,dis(tmp[i],tmp[j]));
        }
    }
    return ret;
}




int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmpxy);
        printf("%.2lf\n",closestPair(0,n-1)/2);
    }
    return 0;
}
