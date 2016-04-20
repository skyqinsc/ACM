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
priority_queue
/******************auther:ACsorry******************/

//以下为倍增算法求后缀数组
int wa[N],wb[N],wv[N],Ws[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(const char *r,int *sa,int n,int m){
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i<m;i++) Ws[i]=0;
	for(i=0;i<n;i++) Ws[x[i]=r[i]]++;
	for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
	for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;
	for(j=1,p=1;p<n;j*=2,m=p){
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) wv[i]=x[y[i]];
		for(i=0;i<m;i++) Ws[i]=0;
		for(i=0;i<n;i++) Ws[wv[i]]++;
		for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
		for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
int sa[N],Rank[N],height[N];
//求height数组
void calheight(const char *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) Rank[sa[i]]=i;
	for(i=0;i<n;height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}

int dp[N][20];

void Rmq_init(int n)
{
    int m=floor(log(n+0.0)/log(2.0));
    for(int i=1;i<=n;i++) dp[i][0]=height[i];
    for(int j=1;j<=m;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int Rmq_query(int L,int R)
{
    int a=Rank[L],b=Rank[R];
    if(a>b) swap(a,b);
    a++;
    int m=floor((log(b-a+1.0)/log(2.0)));
    return min(dp[a][m],dp[b-(1<<m)+1][m]);
}

char str[N];


int main()
{
    int cas=0;
    while(scanf("%s",str)==1&&str[0]!='#')
    {
        int n=strlen(str);
        da(str,sa,n+1,130);
        calheight(str,sa,n);
        Rmq_init(n);
        int cnt=0,maxx=0,a[N];
        for(int l=1;l<n;l++){
            for(int i=0;i+l<n;i+=l){ //j+=l.复杂度的需要
                int r=Rmq_query(i,i+l);
                int step=r/l+1;
                int k=i-(l-r%l);
                if(k>=0&&r%l){
                    if(Rmq_query(k,k+l)>=r)
                        step++;
                }
                if(step>maxx)
                {
                    maxx=step;
                    cnt=0;
                    a[cnt++]=l;
                }
                else if(step==maxx)
                    a[cnt++]=l;
            }
        }

        int len=-1,st;
        for(int i=1;i<=n&&len==-1;i++){
            for(int j=0;j<cnt;j++){
                if(Rmq_query(sa[i],sa[i]+a[j])/a[j]+1==maxx)
                {
                    len=a[j];
                    st=sa[i];
                    break;
                }
            }
        }

        str[st+maxx*len]=0;
        printf("Case %d: %s\n",++cas,str+st);
    }
    return 0;
}
