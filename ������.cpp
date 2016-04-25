/*
1    2    3   4    5
12   13   14  6
11   15   7
10   8
9
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int arr[100][100];

int main()
{
	int n;
	while(cin>>n){
		int idx=1;
		memset(arr,0,sizeof arr);
		int x=-1,y=0;
		while(idx<=(1+n)*n/2){
			while(x+1<n&&arr[y][x+1]==0) arr[y][++x]=idx++;
			while(x-1>=0&&arr[y+1][x-1]==0) arr[++y][--x]=idx++;
			while(y-1>=0&&arr[y-1][x]==0) arr[--y][x]=idx++;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i;j++){
				printf("%-3d ",arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
