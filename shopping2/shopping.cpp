/*
ID: cussyou1
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int ArraySize=6;
int minPaid[ArraySize][ArraySize][ArraySize][ArraySize][ArraySize];

class product{
public:
	product():id(0),num(0){}
	friend bool operator<(const product &a,const product & b)
	{
		if(a.id<b.id) return true;
		return false;
	}
	int id;
	int num;
};
class special{
public:
	special():price(0)
	{
		for(int i=0;i<5;++i){
			prod[i].id=0;
			prod[i].num=0;
		}
	}
	int price;
	product prod[5];
};

vector<special> spcs;
product toBuy[5];

void init();
void read();
void printRead();
void printMin();
bool isOut(int a[],int size);

int main()
{
	// init
	init();
	// read
	read();
	//printRead();
	// remove some invalid specials
	//
	minPaid[0][0][0][0][0]=0;
	// dynamic program
	int a[5];
	for(a[0]=0;a[0]<=toBuy[0].num;++a[0])
		for(a[1]=0;a[1]<=toBuy[1].num;++a[1])
			for(a[2]=0;a[2]<=toBuy[2].num;++a[2])
				for(a[3]=0;a[3]<=toBuy[3].num;++a[3])
					for(a[4]=0;a[4]<=toBuy[4].num;++a[4]){
						int b[5];
						// every special
						for(int i=0;i<spcs.size();++i){
							for(int j=0;j<5;++j) b[j]=a[j]+spcs[i].prod[j].num;
							// check
							if(!isOut(b,5)){
								if(minPaid[a[0]][a[1]][a[2]][a[3]][a[4]]+spcs[i].price<minPaid[b[0]][b[1]][b[2]][b[3]][b[4]]){
									minPaid[b[0]][b[1]][b[2]][b[3]][b[4]]=minPaid[a[0]][a[1]][a[2]][a[3]][a[4]]+spcs[i].price;
									//cout<<minPaid[b[0]][b[1]][b[2]][b[3]][b[4]]<<' '<<endl;
								}
							}else{
								//cout<<minPaid[b[0]][b[1]][b[2]][b[3]][b[4]]<<' ';
							}
						}
					}
					ofstream fout("shopping.out");
					fout<<minPaid[toBuy[0].num][toBuy[1].num][toBuy[2].num][toBuy[3].num][toBuy[4].num]<<endl;
					return 0;
}
bool isOut(int a[],int size)
{

	for(int i=0;i<size;++i){
		if((a[i]>=ArraySize)||(a[i]>toBuy[i].num)) return true;
	}
	return false;
}
void init()
{
	for(int a1=0;a1<ArraySize;++a1)
		for(int a2=0;a2<ArraySize;++a2)
			for(int a3=0;a3<ArraySize;++a3)
				for(int a4=0;a4<ArraySize;++a4)
					for(int a5=0;a5<ArraySize;++a5)
						minPaid[a1][a2][a3][a4][a5]=0x2fffffff;
}
void read()
{
	int num;
	vector<special> tmpspc;
	ifstream fin("shopping.in");
	fin>>num;
	// read special
	for(int i=0;i<num;++i){
		int n;
		fin>>n;
		special tmp;
		for(int j=0;j<n;++j){
			fin>>tmp.prod[j].id>>tmp.prod[j].num;
		}
		fin>>tmp.price;
		tmpspc.push_back(tmp);
	}
	// read to buy
	fin>>num;
	for(int i=0;i<num;++i){
		fin>>toBuy[i].id>>toBuy[i].num;
		special tmp;
		fin>>tmp.price;
		tmp.prod[4].id=toBuy[i].id;// put to the end
		tmp.prod[4].num=1;
		tmpspc.push_back(tmp);
	}
	//printRead();
	// sort
	sort(toBuy,toBuy+5);
	int position[1000];
	int buynum[1000];
	for(int i=0;i<1000;++i){
		position[i]=-1;
		buynum[i]=0;
	}
	for(int i=0;i<5;++i){
		position[toBuy[i].id]=i;
		buynum[toBuy[i].id]=toBuy[i].num;
	}
	for(int i=0;i<tmpspc.size();++i){
		special tmp;
		bool isValid=true;
		for(int j=0;j<5;++j){
			if(buynum[tmpspc[i].prod[j].id]<0){
				isValid=false;
				break; // not buy this product
			}
			tmp.prod[position[tmpspc[i].prod[j].id]]=tmpspc[i].prod[j];
		}
		if(isValid){
			tmp.price=tmpspc[i].price;
			spcs.push_back(tmp);
		}
	}
}
void printRead()
{
	cout<<"specials: "<<endl;
	for(int i=0;i<spcs.size();++i){
		cout<<"price:"<<spcs[i].price<<"\n\t";
		for(int j=0;j<5;++j){
			cout<<spcs[i].prod[j].id<<' '<<spcs[i].prod[j].num<<';';
		}
		cout<<endl;
	}
	cout<<"to buy:"<<"\n\t";
	for(int j=0;j<5;++j)
		cout<<toBuy[j].id<<' '<<toBuy[j].num<<';';
	cout<<endl;
}
void printMin(int a1,int a2,int a3,int a4,int a5)
{
	cout<<minPaid[a1][a2][a3][a4][a5];
}
