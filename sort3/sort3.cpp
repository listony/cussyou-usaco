/*
ID: cussyou1
PROG: sort3
LANG: C++
*/

#include <fstream>

using namespace std;

const int MaxSize = 1000;
int sequence[MaxSize];
int incseq[MaxSize];
int counter[4]={0,0,0,0};

// and change the sort
int find2(const int i, int limit)
{
	if(sequence[i]==incseq[i]) return 1;
	for(int k=i+1;k<limit;++k){
		if((sequence[k]==incseq[i])&&(incseq[k]==sequence[i])){ // exchange them
			sequence[i]=incseq[i];
			sequence[k]=incseq[k];
		       return 1;
		}
	}
	return 0;
}
int find3(const int i, int limit)
{
	int a,b;
	a=sequence[i];
	b=incseq[i];
	if(a==b) return 1;

	sequence[i]=incseq[i];

	int c = 6-a-b;
	int ind1,ind2;
	int k;
	for(k=i+1;k<limit;++k){
		if((sequence[k]==b)&&(incseq[k]==c)){
			sequence[k]=incseq[k];
			break;
		}
	}
	if(k==limit) return 0;
	for(k=i+1;k<limit;++k){
		if((sequence[k]==c)&&(incseq[k]==a)){
			sequence[k]=incseq[k];
			break;
		}
	}
	if(k==limit) return 0;
	return 1;
}
int main()
{
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int size;
	fin>>size;
	for(int i=0;i<size;++i){
		fin>>sequence[i];
		++counter[sequence[i]];
	}
	for(int i=0;i<counter[1];++i){
		incseq[i]=1;
	}
	for(int i=0;i<counter[2];++i){
		incseq[counter[1]+i]=2;
	}
	for(int i=0;i<counter[3];++i){
		incseq[i+counter[1]+counter[2]]=3;
	}
	// count
	int num=0;
	for(int i=0;i<size;++i){
		if(sequence[i]==incseq[i]) continue;
		if(find2(i,size)){
			++num;
		}else if(find3(i,size)){
			num=num+2;
		}else{// some error
		}
	}
	fout<<num<<endl;
	return 0;
}
