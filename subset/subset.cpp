/*
ID: cussyou1
PROG: subset
LANG: C++
*/

#include <fstream>
#include <list>

using namespace std;

const int MaxSum = 1024;
const int MaxNum = 39;

int counter[MaxSum+1][MaxNum+1];


int main() {
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    int n;
    fin >> n;
    int sum = n*(n+1)/4;

    for(int i=0;i<=MaxSum;++i){
        for(int j=0;j<=MaxNum;++j){
            counter[i][j]=0;
        }
    }
    //
    counter[1][1]=1;
    for ( int i=2;i<=n;++i){
        for(int j=0;j<=sum;++j){
            counter[j][i]=counter[j][i-1];
        }
        for(int j=0;j<=sum-i;++j){
            counter[j+i][i]+=counter[j][i-1];
        }
    }
    fout<<counter[sum][n];
    return 0;
}

