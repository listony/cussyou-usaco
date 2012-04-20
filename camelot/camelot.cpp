/*
ID: cussyou1
PROG: camelot
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>

using namespace std;

const int RowMax = 30;
const int ColMax = 26;
int board[RowMax][ColMax];
int rowSize,colSize;

int tmpbd[RowMax][ColMax];
int tmpbd2[RowMax][ColMax];

struct node {
	int r,c;
	int level;
};

int kingR,kingC;
int knights;

void init();
void read();
void findPoints();
int kingMove();
void printStatus(int a[][ColMax],int m,int n);

int main()
{
	init();
	read();
	//    printStatus(board,rowSize,colSize);

	// find gathering points
	findPoints();
	//  printStatus(tmpbd2,rowSize,colSize);

	int minMove=0x2fffffff;
	int k=kingMove();
	for(int i=0;i<rowSize;++i){
		for(int j=0;j<colSize;++j){
			if(tmpbd2[i][j]>-1){
				if(minMove>tmpbd2[i][j]){
					minMove=tmpbd2[i][j];
				}
			}
		}
	}
	ofstream fout("camelot.out");
	fout<<minMove+k<<endl;
	return 0;
}
int kingMove()
{
	//cout<<"king: "<<kingR<<' '<<kingC<<endl;
	int k=0x2fffffff;
	for(int i=0;i<rowSize;++i){
		for(int j=0;j<colSize;++j){
			if(tmpbd2[i][j]!=-1){
				int v = 0;
				if(i>kingR) v+=i-kingR;
				else v+=kingR-i;
				if(j>kingC) v+=j-kingC;
				else v+=kingC-j;
				if(v<k){
					k=v;
					//cout<<k<<' ';
				}
			}
		}
	}
	return k;
}
inline bool isOut(int i,int j)
{
	if((i<0)||(i>=rowSize)) return true;
	if((j<0)||(j>=colSize)) return true;
	return false;
}
void fillbd(int i,int j,int n)
{
	if((tmpbd[i][j]!=-1)&&(tmpbd[i][j]<n)) return;
	// next level
	if(!isOut(i+1,j-2)){

	}
	if(!isOut(i+2,j+1)){

	}
	if(!isOut(i+2,j-1)){

	}
	if(!isOut(i-1,j+2)){

	}
	if(!isOut(i-1,j-2)){

	}
	if(!isOut(i-2,j+1)){

	}
	if(!isOut(i-2,j-1)){

	}
}
void findPoints()
{
	for(int m=0;m<rowSize;++m){
		for(int n=0;n<colSize;++n){
			tmpbd2[m][n]=-1;
		}
	}
	for(int i=0;i<rowSize;++i){
		for(int j=0;j<colSize;++j){
			if(board[i][j]>0){
				for(int m=0;m<rowSize;++m){
					for(int n=0;n<colSize;++n){
						tmpbd[m][n]=-1;
					}
				}
				fillbd(i,j,0);
				//		printStatus(tmpbd,rowSize,colSize);
				// copy to other
				for(int m=0;m<rowSize;++m){
					for(int n=0;n<colSize;++n){
						if(tmpbd[m][n]!=-1){
							if(tmpbd2[m][n]!=-1){
								tmpbd2[m][n]+=tmpbd[m][n];
							}else{
								tmpbd2[m][n]=tmpbd[m][n];
							}
						}
					}
				}
			}
		}
	}

}
void read()
{
	ifstream fin("camelot.in");
	fin>>rowSize>>colSize;
	// read king
	int r;
	char c;
	fin>>c>>r;
	kingR=r-1;
	kingC=c-'A';
	// read knights
	knights=0;
	while(1){
		fin>>c>>r;
		if(fin.bad()||fin.eof()) break;
		board[r-1][c-'A']=1;
		knights++;
	}
}
void printStatus(int bd[][ColMax],int m,int n)
{
	cout<<"board:"<<endl;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout.width(4);
			cout<<bd[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
void init()
{
	for(int i=0;i<RowMax;++i){
		for(int j=0;j<ColMax;++j){
			board[i][j]=0;
		}
	}
}
