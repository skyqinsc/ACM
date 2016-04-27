#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

char anum[500],bnum[500];
int a[500],b[500],c[500];

char * multi(char *anum,char *bnum){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	int la=strlen(anum),lb=strlen(bnum),lc;
	cout<<la<<" - "<<lb<<endl;
	for(int i=0;i<la;i++) a[la-i]=anum[i]-48;
	for(int i=0;i<lb;i++) b[lb-i]=bnum[i]-48;
	for(int i=1;i<=la;i++){
		int x=0;
		for(int j=1;j<=lb;j++){
			c[i+j-1]=c[i+j-1]+a[i]*b[j]+x;
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lb]=x;
	}
	lc=la+lb;
	while(c[lc]==0&&lc>1) lc--;
	char *ret=new char[lc+1];
	for(int i=1;i<=lc;i++){
		ret[lc-i]=c[i]+48;
		cout<<"="<<c[i]<<endl;
	}
	ret[lc]=0;
	return ret;

}

int main(){
	while(cin>>anum>>bnum){
		cout<<multi(anum,bnum)<<endl;
	}
	return 0;
}
