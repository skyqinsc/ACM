#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000007
using namespace std;

unsigned long long dp_1[100010][2];
unsigned long long dp_2[100010][2];
char s1[110],s2[110];
int len1,len2,ls1,ls2;
int main(){
    while(cin>>&s1[1]>>&s2[1]>>len1>>len2){
        ls1=strlen(s1+1);
        ls2=strlen(s2+1);
        dp_1[1][0]=s1[1]-'a';dp_1[1][1]=1;
        for(int i=2;i<=len2;i++){
            if(i<=ls1){
                dp_1[i][1]=dp_1[i-1][1];
                dp_1[i][0]=(dp_1[i-1][0]*26+dp_1[i-1][1]*(s1[i]-'a'));
            }
            else{
                dp_1[i][1]=0;
                dp_1[i][0]=dp_1[i-1][0]*26;
            }
        }
		//for(int i=1;i<=len2;i++){
		//	printf("1:  %2d:%I64d %I64d\n",i,dp_1[i][0],dp_1[i][1]);
		//}
        dp_2[1][0]=s2[1]-'a';dp_2[1][1]=1;
        for(int i=2;i<=len2;i++){
            if(i<=ls2){
                dp_2[i][1]=dp_2[i-1][1];
                dp_2[i][0]=(dp_2[i-1][0]*26+dp_2[i-1][1]*(s2[i]-'a'));
            }
            else{
                dp_2[i][1]=0;
                dp_2[i][0]=dp_2[i-1][0]*26;
            }
        }
        int tmp1=0,tmp2=0;
        for(int i=len1;i<=len2;i++){
            tmp1=tmp1+dp_1[i][0]+dp_1[i][1];
            tmp2=tmp2+dp_2[i][0]+dp_2[i][1];
        }
		//for(int i=1;i<=len2;i++){
		//	printf("2:  %2d:%I64d %I64d\n",i,dp_2[i][0],dp_2[i][1]);
		//}
        cout<<(tmp2-tmp1-1)%MOD<<endl;
    }
    return 0;
}

/*
kcnmi
lgtqj
5 5
*/