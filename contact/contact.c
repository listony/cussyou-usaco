/*
ID: cussyou1
PROG: contact
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MaxL 20000 
#define MaxF 8192

char str[MaxL];
int slen;

int fre[MaxF];

int smin,smax; // step value
int num;

// binary string to int
int str2int(char *str,int len)
{
	int re;
	int i;
	re=0;
	for(i=0;i<len;++i){
		re+=re<<1+str[i]-'1';
	}
}

char* int2str(char* buf, int n, int len)
{
	int i=0,j=0;
	for(i=0;i<len;++i){
		int t=n%2;
		n=n/2;
		buf[i]='0'+t;
	}
	buf[len]=0;
	// rev
	for(i=0,j=strlen(buf)-1;i<j;++i,--j){
		char c=buf[i];
		buf[i]=buf[j]
		buf[j]=c;
	}
	return buf;
}
int main()
{
	int i,j;

	FILE *fin,*fout;
	fin=fopen("contact.in","r");
	fout=fopen("contact.out","w");
	// init
	str[0]=0;
	slen=0;
	memset(fre,0,sizeof(fre[0])*MaxF);
	// read all
	fscanf(fin,"%d %d %d",&smin,&smax,&num);
	while(1){
		char buf[120];
		char *line;
		line=fgets(buf,sizeof(buf),fin);
		if(line==NULL) break;
		line[strlen(line)-1]=0;
		if(isalpha(line[0])){
			strcat(str,line);
		}
	}
	slen=strlen(str);
	//
	for(i=0;i<slen-1;++i){
		for(j=smin;j<=smax;++j){
			int f;
			if(i+j>slen){
				break;
			}
			f=str2int(str+i,j);
			++fre[f];
		}
	}
	// sort

	// output
	j=0;
	for(i=0;i<num;++i){
		int k;
		fprintf(fout,"%d\n",fre[j]);
		fprintf(fout,"%s",int2str(j,
	}
	fclose(fin);
	fclose(fout);
	return 0;
}