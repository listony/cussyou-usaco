/*
ID: cussyou1
PROG: inflate
LANG: C
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxM 10001

int main()
{
	int points[MaxM]; // pointes[i] - the max pointe to could get in "i" minutes
	int minutes,num;
	int i,j;
	FILE *fin, *fout;
	fin=fopen("inflate.in","r");
	fout=fopen("inflate.out","w");
	// init
	memset(points,0,sizeof(int)*MaxM);
	// read
	fscanf(fin,"%d %d",&minutes,&num);
	for(i=0;i<num;++i){
		int m,n;
		fscanf(fin,"%d %d",&n,&m);
		if(points[m]<n){
			points[m]=n;
		}
	}
	// dynamic program
	for(i=0;i<=minutes;++i){
		for(j=0;j<=i;++j){
			if((i+j<=minutes)&&(points[i]+points[j]>points[i+j])){
				points[i+j]=points[i]+points[j];
			}
		}
	}
	for(i=minutes;i>0;--i){
		if(points[i]>0){
			break;
		}
	}
	fprintf(fout,"%d\n",points[i]);
	return 0;
}