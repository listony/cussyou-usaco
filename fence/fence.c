

/*
ID: cussyou1
PROG: fence
LANG: C
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MaxN 501
#define MaxC 1040

struct link{
	int n;
	struct link *next;
};

struct adj{
	int size;
	struct link* head;
};
/* adj table */
struct adj adjt[MaxN];
void adj_insert(int ind, int x);
int num; // num of edges

int map[MaxN][MaxN];
int output[MaxC];

void read();

int dfs(FILE* fout,int size);

int main()
{
	int i,j;
	int re;
	FILE *fout;
	fout=fopen("fence.out","w");
	read();
	//
	for(i=1;i<MaxN;++i){
		if(adjt[i].size%2==1)
			break;
	}
	if(i==MaxN){
		for(i=1;i<MaxN;++i){
			if (adjt[i].size) break;
		}
		output[0]=i;
		dfs(fout,1);
	}else{
		output[0]=i;
		dfs(fout,1);
	}
	fclose(fout);
	return 0;
}

int dfs(FILE* fout,int size)
{
	if(size>num){
		int i;
		for(i=0;i<size;++i){
			fprintf(fout,"%d\n",output[i]);
		}
		return 1;
	}else{
		struct link* next=adjt[output[size-1]].head;
		while(next!=0){
			int re;
			if(map[output[size-1]][next->n]==0){
				next=next->next;
				continue;
			}
			output[size]=next->n;
			map[output[size-1]][next->n]--;
			map[next->n][output[size-1]]--;
			re=dfs(fout,size+1);
			//map[output[size-1]][next->n]++;
			//map[next->n][output[size-1]]++;
			if(re) 
				return 1;
			else{
				next=next->next;
			}
		}
		return 0;
	}	
}

void read()
{
	FILE* fin;
	int i,j;
	fin=fopen("fence.in","r");
	fscanf(fin,"%d",&num);
	for(i=0;i<MaxN;++i){
		adjt[i].size=0;
		adjt[i].head=0;
	}
	for(i=0;i<MaxN;++i){
		for(j=0;j<MaxN;++j){
			map[i][j]=0;
		}
	}
	for(i=0;i<num;++i){
		int x,y;
		fscanf(fin,"%d %d",&x,&y);
		adj_insert(x,y);
		adj_insert(y,x);
		map[x][y]++;
		map[y][x]++;
	}
	fclose(fin);
}

void adj_insert(int ind, int x)
{
	struct link * t = malloc(sizeof(struct link));
	t->n=x;
	t->next=0;

	if(adjt[ind].head==0){
		adjt[ind].head=t;
		++adjt[ind].size;
	}else{
		struct link *p=adjt[ind].head;
		struct link *q=p->next;
		// comp the first
		if(p->n>x){
			adjt[ind].head=t;
			t->next=p;
			++adjt[ind].size;
			return;
		}
		while((q!=0)&&(q->n<x)) { p=q;q=q->next;}
		if(q==0){ // the last one
			p->next=t;
			++adjt[ind].size;
		}else {
			t->next=q;
			p->next=t;
			++adjt[ind].size;
		}
	}	
}