#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void generateGery(vector<string> &code,int n){
	if(n==1){
		code.push_back("0");
		code.push_back("1");
		return;
	}
	generateGery(code,n-1);
	int idx=1<<(n-1);
	for(int i=idx-1;i>=0;i--){
		code.push_back('1'+code[i]);
		code[i]='0'+code[i];
	}
}

int main()
{
	vector<string> code;
	generateGery(code,3);
	for(int i=0;i<(1<<3);i++){
		cout<<code[i]<<endl;
	}
	return 0;
}
