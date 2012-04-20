/*
ID: cussyou1
PROG: kimbits
LANG: C++
*/

#include <fstream>

using namespace std;

const int MaxB = 32;

// table[i][j] means : the number of all possible that a string with i bits and j 1s
int table[MaxB][MaxB];

int main()
{
	int len, counter, mbits;
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");

	fin>>len>>mbits>>counter;

	// init table
	memset(table,0,sizeof(table[0][0])*MaxB*MaxB);
	table[1][1]=1;
	// end init
	// calculate the table[i][j]
	for(int i=1;i<len;++i){
		for(int j=1;j<=i;++j){
			table[i+1][j]+=table[i][j];
			table[i+1][j+1]+=table[i][j];
		}
	}
	// end calculate

	return 0;
}