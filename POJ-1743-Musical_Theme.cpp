/*
      status:
        date:
.........................
 Description:
     * SPOJ 694
     * 给定一个字符串，求不相同子串个数。
     * 每个子串一定是某个后缀的前缀，那么原问题等价于求所有后缀之间的不相同子串个数。
     * 总数为n*(n-1)/2,再减掉height[i]的和就是答案
.........................
  height 数组:
     * 定义 height[i]=suffix(sa[i-1])和 suffix(sa[i])的最长公
     * 共前缀,也就是排名相邻的两个后缀的最长公共前缀
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define lowbit(x) ((x)&(-x))
#define PI acos(-1.0)
#define ls rt<<1
#define rs rt<<1|1
using namespace std;

typedef long long ll;
const int N=100007;

//以下为倍增算法求后缀数组
int wa[N],wb[N],wv[N],Ws[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

//0 ~ n-1
void da(const int *r,int *sa,int n,int m){
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
void calheight(const int *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) Rank[sa[i]]=i;
	for(i=0;i<n;height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}

char s[N];
int ss[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++) ss[i]=s[i];
        ss[len]=0;
        da(ss,sa,len+1,130);
        calheight(ss,sa,len);
        ll ans=0;
        for(int i=2;i<=len;i++)
            ans=ans+height[i];
        printf("%lld\n",len*(len+1)/2-ans);
    }
    return 0;
}

/*  Nothing you can't complete. */
