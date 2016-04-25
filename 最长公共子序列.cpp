#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10010],p[10010];

int dp[10010][10010];

int main()
{
	while(scanf("%s%s",s+1,p+1)==2){
		int ls=strlen(s+1);
		int lp=strlen(p+1);
		for(int i=0;i<=max(ls,lp);i++){
			dp[i][0]=dp[0][i]=0;
		}
		int ans=0;
		for(int i=1;i<=ls;i++){
			for(int j=1;j<=lp;j++){
				if(s[i]==p[j]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=0;
				ans=max(dp[i][j],ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
