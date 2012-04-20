
/*
ID: cussyou1
PROG: butter
LANG: C
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MaxP 800
#define MaxN 500
#define MaxC 1450

struct edge{
	int x,y;
	int d;
};

int dist[MaxP+1];
int pnum=0;

int cow[MaxP+1]; // the pasture where cows are
int cnum=0;

struct edge edges[MaxC];
int ednum=0;

// functions
void printp(FILE* fout);

int main()
{
	int i;
	int minl;
	int ind;
	FILE *fin,*fout;
	
	fin=fopen("butter.in","r");
	fout=fopen("butter.out","w");

	
	fscanf(fin,"%d %d %d",&cnum,&pnum,&ednum);
	// read all 
	for(i=0;i<cnum;++i){
		fscanf(fin,"%d",&cow[i]);
	}
	for(i=0;i<ednum;++i){
		fscanf(fin,"%d %d %d",&edges[i].x,&edges[i].y,&edges[i].d);
	}
	// end read
	
	minl=INT_MAX/2;
	ind=0;
	// every source point
	for(i=1;i<=pnum;++i){ 
		// bellman-ford
		int tmp;
		int j,k;
		int over;
		// init
		for(j=1;j<=pnum;++j){
			dist[j]=INT_MAX/2;
		}
		dist[i]=0; // set source
		// end init
		for(k=0;k<pnum-1;++k){ // pnum times
			over = 1;
			// every edge
			for(j=0;j<ednum;++j){
				if(dist[edges[j].y]>dist[edges[j].x]+edges[j].d){
					dist[edges[j].y]=dist[edges[j].x]+edges[j].d;
					over = 0;
				}
				if(dist[edges[j].x]>dist[edges[j].y]+edges[j].d){
					dist[edges[j].x]=dist[edges[j].y]+edges[j].d;
					over = 0;
				}
			}
			if(over) break; // end of this source point
		}
		// calc min
		tmp=0;
		for(j=0;j<cnum;++j){
			tmp+=dist[cow[j]];
		}
		if(tmp<minl){
			minl=tmp;
			ind=i;
		}
	}

	//output
	fprintf(fout,"%d\n",minl);
	// clean
	fclose(fin);
	fclose(fout);
	return 0;
}
