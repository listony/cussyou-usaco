
/*
ID: cussyou1
PROG: shopping
LANG: C
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct offer{
	int price;
	int pnum;
	int product[5];
	int num[5];
};

struct offer offers[128];
int onum;

struct buy{
	int product;
	int num;
};

struct buy buys[5];
int bnum;

int minp;

void read();
void write();
// the product and nums to buy
void dfs(struct buy *b, int n,int price);

int main()
{
	read();
	minp=10000000;
	dfs(buys,bnum,0);
	write();
	return 0;
}
// return - index of product "p"
int find(struct buy *b, int p)
{
	int i;
	for(i=0;i<bnum;++i){
		if(b[i].product==p) return i;
	}
	return -1;
}

void dfs(struct buy *b, int n, int p)
{
	int i;
	if(n==0){ // output
		if(p<minp) minp=p;
		return;
	}
	// choose a offer from array and deep search
	for(i=0;i<onum;++i){
		int j;
		struct buy newb = *b;
		int ok=1;
		
	}
}

void read()
{
	FILE* fin;
	int i;
	fin=fopen("shopping.in","r");
	fscanf(fin,"%d",&onum);
	for(i =0 ;i<onum;++i){
		int j;
		fscanf(fin,"%d",&offers[i].pnum);
		for(j=0;j<offers[i].pnum;++j){
			int x,y;
			fscanf(fin,"%d %d",&x,&y);
			offers[i].product[j]=x;
			offers[i].num[j]=y;
		}
		// read price
		fscanf(fin,"%d",&offers[i].price);
	}
	// read want to buy
	fscanf(fin,"%d",&bnum);
	for(i=0;i<bnum;++i){
		int p;
		fscanf(fin,"%d %d %d",&buys[i].product,&buys[i].num,&p);
		// add to offers
		offers[onum].price=p;
		offers[onum].pnum=1;
		offers[onum].product[0]=buys[i].product;
		offers[onum].num[0]=1;
		onum++;
	}
}
void write()
{
	FILE* fout;
	fout=fopen("shopping.out","w");
	fprintf(fout,"%d",minp);
	fclose(fout);
}