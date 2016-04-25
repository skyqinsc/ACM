#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int cnt;
void solve(char *str,int idx){
    if(idx==strlen(str)-1){
        printf("%3d:%s\n",++cnt,str);
        return;
    }
    for(int i=idx;i<strlen(str);i++){
        swap(str[idx],str[i]);
        solve(str,idx+1);
        swap(str[idx],str[i]);
    }
}

int main(){
    char str[100010];
    while(cin>>str){
        cnt=0;
        solve(str,0);
    }
    return 0;
}

