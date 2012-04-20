/*
ID: cussyou1
PROG: hamming
LANG: C++
*/

#include <fstream>
#include <algorithm>

using namespace std;

int codeArray[256];
int codeNum=0;
int distance(const int a, const int b, const int len)
{
	int d=0;
	for(int i=0;i<len;++i){
		int test=1<<i;
		int tmp1,tmp2;
		tmp1=a&test;
		tmp2=b&test;
		if(tmp1!=tmp2) ++d;
	}
	return d;
}
int main()
{
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	int num;
	int bits;
	int dsts;
	fin>>num>>bits>>dsts;
	// all
	int max = 1<<bits;
	codeArray[0]=0;
	codeNum=1;
	for(int i=1;i<max;++i){
		bool isNew=true;
		for(int j=0;j<codeNum;++j){
			if(distance(i,codeArray[j],bits)<dsts){
				isNew=false;
				break;
			}
		}
		if(isNew){
			codeArray[codeNum]=i;
			++codeNum;
			if(codeNum>=num) break;
		}
	}
	for(int i=0;i<codeNum-1;++i){
		fout<<codeArray[i];
		if(i % 10 != 9) fout<<" ";
		else fout<<endl;
	}
	fout<<codeArray[codeNum-1]<<endl;
	return 0;
}
