/*
ID: cussyou1
PROG: msquare
LANG: C
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 8! = 40320 
#define MaxS 40320

struct square{
	int table[2][4];
};

struct node {
	struct square state;
	int pre; // a pointer of parent
	char opt; // A B or C
};

struct square init;
struct square dest;

int lev[8];

struct node sqs[MaxS];
int slen;
// record whether a square has existed or not
// hash...
char flags[MaxS];

// functions
void aoprt(struct square*);
void boprt(struct square*);
void coprt(struct square*);

int find(struct square *a);
int equal(struct square *a, struct square *b);

// debug
void print(FILE* fout,struct node *a);

int main()
{
	struct node *result=0;
	int i,j;
	FILE *fin,*fout;

	fin=fopen("msquare.in","r");
	fout=fopen("msquare.out","w");
	// read and init
	for(i=0;i<4;++i){
		init.table[0][i]=i+1;
		fscanf(fin,"%d",&dest.table[0][i]);
	}
	for(i=3;i>=0;--i){
		init.table[1][i]=8-i;
		fscanf(fin,"%d",&dest.table[1][i]);
	}
	// init
	lev[0]=0;
	lev[1]=1;
	for(i=2;i<8;++i){
		lev[i]=i*lev[i-1];
	}
	memset(flags,0,sizeof(flags[0])*MaxS);
	// end init

	flags[0]=1;
	sqs[0].state=init;
	slen=1;
	i=0;
	while(i<MaxS){
		struct square a,b,c;
		//print(fout,&sqs[i]);
		if(equal(&sqs[i].state,&dest)){
			break;
		}
		// add childs
		a=sqs[i].state;
		b=sqs[i].state;
		c=sqs[i].state;
		aoprt(&a);
		boprt(&b);
		coprt(&c);
		if(!find(&a)){
			sqs[slen].state=a;
			sqs[slen].opt='A';
			sqs[slen].pre=i;
			++slen;
		}
		if(!find(&b)){
			sqs[slen].state=b;
			sqs[slen].opt='B';
			sqs[slen].pre=i;
			++slen;
		}
		if(!find(&c)){
			sqs[slen].state=c;
			sqs[slen].opt='C';
			sqs[slen].pre=i;
			++slen;
		}
		// next i
		++i;
	}	
	//
	// output
	if(i<MaxS){
		int len=0;
		char opts[32];
		for(j=i;j>0;j=sqs[j].pre){
			opts[len++]=sqs[j].opt;
		}
		fprintf(fout,"%d\n",len);
		for(j=len-1;j>=0;--j){
			fprintf(fout,"%c",opts[j]);
		}
		fprintf(fout,"\n");
	}else{
		fprintf(fout,"none\n");
	}
	// clean
	fclose(fin);
	fclose(fout);
	return 0;
}
// A,B,C oprations
void aoprt(struct square *s)
{
	int i;
	for(i=0;i<4;++i){ // exchage
		int tmp=s->table[0][i];
		s->table[0][i]=s->table[1][i];
		s->table[1][i]=tmp;

	}
}
void boprt(struct square *s)
{
	int tmp1,tmp2,i;
	tmp1=s->table[0][3];
	tmp2=s->table[1][3];
	for(i=2;i>=0;--i){
		s->table[0][i+1]=s->table[0][i];
		s->table[1][i+1]=s->table[1][i];
	}
	s->table[0][0]=tmp1;
	s->table[1][0]=tmp2;
}
void coprt(struct square *s)
{
	int tmp=s->table[0][1];
	s->table[0][1]=s->table[1][1];
	s->table[1][1]=s->table[1][2];
	s->table[1][2]=s->table[0][2];
	s->table[0][2]=tmp;
}
// is equal
int equal(struct square *a, struct square *b)
{
	int i,j;
	for(i=0;i<2;++i){
		for(j=0;j<4;++j){
			if(a->table[i][j]!=b->table[i][j]) return 0;
		}
	}
	return 1;
}
// find in a hash table
int find(struct square *a)
{
	int i,j;
	// hash!
	int tmp[8];
	int seq[9];
	int mul=0;
	for(i=0;i<4;++i){
		tmp[i]=a->table[0][i];
	}
	for(i=0;i<4;++i){
		tmp[4+i]=a->table[1][3-i];
	}
	for(i=0;i<9;++i) seq[i]=0;
	for(i=6;i>=0;--i){
		for(j=i+1;j<8;++j){
			if(tmp[i]>tmp[j]){
				++seq[tmp[i]];
			}
		}
	}
	for(i=2;i<=8;++i){
		mul=mul+seq[i]*lev[i-1];
	}
	if(flags[mul]==1) return 1;
	flags[mul]=1;
	return 0;
}

void print(FILE* fout,struct node *a)
{
	int i,j;
	fprintf(fout,"%d %c\n", a->pre,a->opt);
	for(i=0;i<2;++i){
		for(j=0;j<4;++j){
			fprintf(fout,"%d",a->state.table[i][j]);
		}
		fprintf(fout,"\n");
	}
}