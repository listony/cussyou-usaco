/*
ID: cussyou1
PROG: humble
LANG: C
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MaxK 100
#define MaxH 100000

int comp(int *a, int *b)
{
	if(*a==*b) return 0;
	if(*a>*b) return 1;
	return -1;
}

int main()
{
	int hum[MaxH];
	int hnum;
	int kset[MaxK];
	int knum;
	int kp[MaxK];
	int num;
	int i,j;
	FILE *fin, *fout;
	fin=fopen("humble.in","r");
	fout=fopen("humble.out","w");
	
	// read
	fscanf(fin,"%d %d",&knum,&num);
	for(i=0;i<knum;++i){
		fscanf(fin,"%d",&kset[i]);
	}
	// init
	qsort(kset,knum,sizeof(kset[0]),comp);
	hnum=0;
	hum[hnum++]=1;
	for(i=0;i<knum;++i) kp[i]=0;

	// find all
	while(hnum<=num){
		int min;
		min=INT_MAX;
		// find next humble
		for(i=0;i<knum;++i){
			int tmp=INT_MAX;
			for(j=0;j<hnum;++j){
				tmp=kset[i]*hum[kp[i]];
				if(tmp>hum[hnum-1]){
					break;
				}else{
					++kp[i];
				}
			}
			if(tmp<min){
				min=tmp;
			}
		}
		hum[hnum++]=min;
	}

	fprintf(fout,"%d\n",hum[num]);
	
	fclose(fin);
	fclose(fout);
	return 0;
}