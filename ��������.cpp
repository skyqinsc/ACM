#include <stdio.h>

void countSort(int arr[],int n){
	int cnt[100]={0},*s_arr=new int[n];
	for(int i=0;i<n;i++) cnt[arr[i]]++;
	for(int i=0;i<100;i++) if(i-1>=0) cnt[i]=cnt[i]+cnt[i-1];
	for(int i=0;i<n;i++){
		s_arr[--cnt[arr[i]]]=arr[i];
	}
	for(int i=0;i<n;i++) arr[i]=s_arr[i];
}

int main(int argc, char *argv[])
{
	int arr[]={5,3,1,2,3,4,8,9,4,5};
	countSort(arr,10);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
