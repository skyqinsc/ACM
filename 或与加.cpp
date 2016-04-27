#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;
typedef unsigned long long ull;
vector<int> pos_0;

int main(){
    ull x,y,k;
    while(cin>>x>>k){
        int p_1=-1;
        for(int i=31;i>=0;i--){
            if(p_1==-1 && (x&(1L<<i))!=0) p_1=i;
            if(p_1!=-1 && (x&(1L<<i))==0) pos_0.push_back(1<<i);
        }
        y=0;
        if(k < (1<<(int)pos_0.size())){
            for(int i=0;i<pos_0.size();i++){
                if(k&(1L<<i)) y=y+pos_0[pos_0.size()-1-i];
            }
        }
        else{
            ull t1=k / (1L<<(int)pos_0.size());
            ull t2=k-t1*(1L<<(int)pos_0.size());
            ull y1=0;
            for(int i=0;i<pos_0.size();i++){
                if(t2&(1L<<i)) y1=y1+pos_0[pos_0.size()-1-i];
            }
            ull y2=t1<<(p_1+1);
            y=y1+y2;
        }
        cout<<y<<endl;

    }
    return 0;
}
