/* 
*    Algorithm: 矩阵快速幂
*         Date: 2015-08-26
*      Contest: WUST2015暑假训练赛14（2015-8-25）-B
*/
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

struct Matrix{
	int sz;
	int mat[110][110];
	Matrix(int sz)
	{
		this->sz=sz;
		for(int i=1;i<=sz;i++)
			for(int j=1;j<=sz;j++)
				mat[i][j]=0;
	}
	void output()
	{
		for(int i=1;i<=sz;i++)
		{
			for(int j=1;j<=sz;j++)
				printf("%d",mat[i][j]);
			printf("\n");
		}
		cout<<"___________"<<endl;
	}

};


Matrix mul(Matrix a,Matrix b)
{
	Matrix ret(a.sz);
	int sz=a.sz;
	for(int i=1;i<=sz;i++)
	{
		for(int j=1;j<=sz;j++)
		{	
			for(int k=1;k<=sz;k++)
				ret.mat[i][j]^=(a.mat[i][k]*b.mat[k][j]);
		}
	}
	return ret;
}

Matrix qpow(Matrix a,int b)
{
	Matrix ret(a.sz);
	for(int i=1;i<=a.sz;i++) ret.mat[i][i]=1;
	while(b)
	{
		if(b&1) ret=mul(ret,a);
		b>>=1;
		a=mul(a,a);
	}
	return ret;
}

char str[110];
int main()
{
	int b;
	while(scanf("%d%s",&b,str)==2)
	{
		int len=strlen(str);
		//cout<<"--"<<str<<endl;
		Matrix tmp(len),a(len);
		for(int i=0;i<len;i++)
			a.mat[1][i+1]=(str[i]=='1'?1:0);
		for(int i=1;i<=len;i++)
			if(i==1) tmp.mat[i][i]=tmp.mat[len][i]=1;
			else tmp.mat[i][i]=tmp.mat[i-1][i]=1;
		//a.output();
		//qpow(tmp,b).output();
		tmp=mul(a,qpow(tmp,b));
		for(int i=1;i<=len;i++)
			printf("%d",tmp.mat[1][i]);
		printf("\n");
	}
	return 0;
}
