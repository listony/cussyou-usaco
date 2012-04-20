
/*
ID: cussyou1
PROG: fence
LANG: C
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MaxN 501
#define MaxC 1200

int map[MaxN][MaxN];

int stack[MaxC];
int slen;

void read();
void write();
void dfs(int i);

int main()
{

	int i,j;
	read();
	for(i=1;i<MaxN;++i){
		if(map[i][0]%2==1)
			break;
	}
	if(i==MaxN){
		for(i=1;i<MaxN;++i){
			if (map[i][0]) break;
		}
		dfs(i);
	}else{
		dfs(i);
	}
	// output
	write();
	return 0;
}

void dfs(int v)
{
	int i;
	for(i=1;i<=500;i++)
		if(map[v][i]>0){
			map[v][i]--;
			map[i][v]--;
			dfs(i);
		}
	stack[slen++]=v;
}
void write()
{
	int i;
	FILE* fout;
	fout=fopen("fence.out","w");
	for(i=slen-1;i>=0;--i){
		fprintf(fout,"%d\n",stack[i]);
	}
	fclose(fout);
}
void read()
{
	FILE* fin;
	int i,j;
	int num;
	fin=fopen("fence.in","r");
	fscanf(fin,"%d",&num);
	
	for(i=0;i<MaxN;++i){
		for(j=0;j<MaxN;++j){
			map[i][j]=0;
		}
	}
	for(i=0;i<num;++i){
		int x,y;
		fscanf(fin,"%d %d",&x,&y);
		map[x][0]++;
		map[y][0]++;
		map[x][y]++;
		map[y][x]++;
	}
	fclose(fin);
}