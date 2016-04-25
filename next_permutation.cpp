#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void next_permutation_(char *str, int sz){
    int i=sz-1,j=sz-1;
    while(i>=0&&str[i]<=str[i-1]) i--;
    if(i==0){
        reverse(str,str+sz);
        return;
    }
    while(str[j]<=str[i-1]) j--;
    swap(str[j],str[i-1]);
    reverse(str+i,str+sz);
}

int main(){
    char str[]="abcd";
    next_permutation_(str,4);
    cout<<str<<endl;
    next_permutation_(str,4);
    cout<<str<<endl;
    return 0;
}
