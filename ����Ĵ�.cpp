#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[100010];
int p[100010];

int main()
{
	while(cin>>str){
		int len=strlen(str);
		for(int i=len;i>=0;i--){
			str[i+i+1]='#';
			str[i+i+2]=str[i];
		}
		str[0]='*';
		int id=0,mx=0;
		for(int i=2;i<len+len+1;i++){
			if(p[id]+id>i) p[i]=min(p[id]+id-i,p[2*id-i]);
			else p[i]=1;
			while(str[i+p[i]]==str[i-p[i]]) p[i]++;
			if(id+p[id]<i+p[i]) id=i;
			if(p[i]-1>mx) mx=p[i]-1;
		}
		cout<<mx<<endl;
	}
	return 0;
}
