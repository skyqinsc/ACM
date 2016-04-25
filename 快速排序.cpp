#include <iostream>
#include <cstdio>
#include <ctime>
#include <random>
using namespace std;

int portion(int arr[],int sz){
    int idx=rand()%sz;
    swap(arr[idx],arr[sz-1]);
    int small=0;
    for(int i=0;i<sz-1;i++){
        if(arr[i]<arr[sz-1]){
            swap(arr[small++],arr[i]);
        }
    }
    swap(arr[small],arr[sz-1]);
    return small;
}

void quick_sort(int arr[],int sz){
    int idx=portion(arr,sz);
    if(idx>0) quick_sort(arr,idx);
    if(idx<sz-1) quick_sort(arr+idx+1,sz-idx-1);
}


int main(){
    srand(unsigned(time(0)));
    int arr[]={1,5,7,3,6,9,4,5,7,8};
    quick_sort(arr,10);
    for(int i=0;i<10;i++)
        printf("%d  ",arr[i]);

    return 0;
}

