/*
ID: cussyou1
PROG: frac1
LANG: C++
*/

#include <fstream>
#include <algorithm>

using namespace std;

const int MaxINT = 160;
struct frac {
	int x;
	int y;
};
frac fracArray[MaxINT*MaxINT];
int fracSize=0;

bool equal(const frac a, const frac b)
{
	if(((a.x)*(b.y))==((b.x)*(a.y))){
		return true;
	}
	return false;
}
bool comp(const frac a, const frac b)
{
	if(((a.x)*(b.y))<((b.x)*(a.y))){
		return true;
	}else if(((a.x)*(b.y))==((b.x)*(a.y))){
		if(a.x<=b.x) return true;
	}
	return false;
}

int main()
{
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int max;
	fin>>max; // read
	// find all fractions
	fracArray[0].x=0;
	fracArray[0].y=1;
	fracSize=1;
	for(int i=1;i<max;++i){
		for(int j=i+1;j<=max;++j){
			fracArray[fracSize].x=i;
			fracArray[fracSize].y=j;
			++fracSize;
		}
	}
	fracArray[fracSize].x=1;
	fracArray[fracSize].y=1;
	++fracSize;
	// sort
	sort(fracArray,fracArray+fracSize,comp);
	// output
	frac tmp;
	tmp.x=-1;
	tmp.y=-1;
	for(int i=0;i<fracSize;++i){
		if(equal(tmp,fracArray[i])) continue;
		tmp=fracArray[i];
		fout<<fracArray[i].x<<"/"<<fracArray[i].y<<endl;
	}
	return 0;
}
