#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[1000],p[1000];

int dp[1010][1010];
int op[1010][1010];

int main()
{
	while(cin>>&str[1]>>&p[1]){
		int ls=strlen(str+1);
		int lp=strlen(p+1);
		for(int i=0;i<=ls;i++){
			dp[i][0]=i;
			op[i][0]=3;
		}
		for(int j=0;j<=lp;j++){
			dp[0][j]=j;
			op[0][j]=4;
		}
		for(int i=1;i<=ls;i++){
			for(int j=1;j<=lp;j++){
				dp[i][j]=1<<29;
				if(str[i]==p[j]) dp[i][j]=dp[i-1][j-1],op[i][j]=1;
				if(str[i]!=p[j]&&dp[i-1][j-1]+1<dp[i][j]) dp[i][j]=dp[i-1][j-1]+1,op[i][j]=2;
				if(dp[i-1][j]+1<dp[i][j]) dp[i][j]=dp[i-1][j]+1,op[i][j]=3;
				if(dp[i][j-1]+1<dp[i][j]) dp[i][j]=dp[i][j-1]+1,op[i][j]=4;
				if(i>=2&&j>=2&&str[i]==p[j-1]&&str[i-1]==p[j]&&dp[i-2][j-2]+1<dp[i][j]) dp[i][j]=dp[i-2][j-2]+1,op[i][j]=5;
			}
		}

		cout<<dp[ls][lp]<<endl;
	}
	return 0;
}

