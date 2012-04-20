/*
ID: cussyou1
PROG: msquare
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 8! = 40320 
#define MaxS 40320

struct square{
	int table[2][4];
};

struct node{
	struct node *next;
	int len;
	char opts[32];
	struct square state;
};

struct square init;
struct square dest;
int states[MaxS];
int lev[8];

struct node* s_crt(struct square *s,int l)
{
	struct node* re=malloc(sizeof(struct node));
	re->next=0;
	re->len=l;
	memcpy(&re->state,s,sizeof(struct square));
	return re;
}
void s_free(struct node * n)
{
	free(n);
	n=0;
}
// stack functions
struct node* s_pop(struct node** head)
{
	struct node* re=0;
	if(*head!=0){
		re=(*head);
		*head=(*head)->next;
	}
	return re;
}
void s_push(struct node** tail, struct node* n)
{
	if(*tail!=0){
		(*tail)->next=n;
		*tail=n;
	}else{
		*tail=n;
	}
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
	if(states[mul]==1) return 1;
	else{
		states[mul]=1; // set this
		return 0;
	}
}
int main()
{
	struct node *head=0,*tail=0;
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
	for(i=0;i<MaxS;++i) states[i]=0;
	// end init 
	head=s_crt(&init,0);
	tail=head;	
	result=head;
	states[0]=1;
	while(head){
		struct node *tmp=s_pop(&head);
		if(!equal(&tmp->state,&dest)){
			struct square a,b,c;
			memcpy(&a,&tmp->state,sizeof(a));
			memcpy(&b,&tmp->state,sizeof(b));
			memcpy(&c,&tmp->state,sizeof(c));
			aoprt(&a);
			boprt(&b);
			coprt(&c);
			if(!find(&a)){
				struct node *t=s_crt(&a,tmp->len+1);
				s_push(&tail,t);

			}
			if(!find(&b)){
				struct node *t=s_crt(&b,tmp->len+1);
				s_push(&tail,t);
			}
			if(!find(&c)){
				struct node *t=s_crt(&c,tmp->len+1);
				s_push(&tail,t);
			}
		}else{
			result=tmp;
			break;
		}

		s_free(tmp);
	}
	// output
	fprintf(fout,"%d\n",result->len);
	for(i=0;i<result->len;++i){
		fprintf(fout,"%c",result->opts[i]);
	}
	// clean
	fclose(fin);
	fclose(fout);
	return 0;
}
