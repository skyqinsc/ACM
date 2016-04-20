/* 
*    Algorithm: 归并排序 求逆序数
*         Date: 2015-08-26
*      Contest: 练习
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int n=500007;
typedef long long ll;

int a[n];
int b[n];
ll ans;
void cal(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	cal(l,mid);cal(mid+1,r);
	int l1=l,l2=mid+1;
	for(int i=l;i<=r;i++)
		if(l2>r||(l1<=mid&&a[l1]<a[l2])) b[i]=a[l1++];
		else b[i]=a[l2++],ans=ans+mid-l1+1;
	for(int i=l;i<=r;i++) a[i]=b[i];
}

int main()
{
	//freopen("in","r",stdin);
	int n;
	while(scanf("%d",&n),n)
	{
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		ans=0;
		cal(1,n);
		printf("%lld\n",ans);
	}
	return 0;
}
