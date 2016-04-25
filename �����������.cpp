#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[10010];
int dp[10010][10010];

int main()
{
	while(cin>>str){
		int len=strlen(str);

		for(int i=len-1;i>=0;i--){
			dp[i][i]=1;
			for(int j=i+1;j<len;j++){
				if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1]+2;
				else
					dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}
