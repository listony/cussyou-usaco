/*
ID: cussyou1
PROG: packrec
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

//
subsequence lcs (string s1, string s2, int i,int j)
{
    if(s1[i]==s2[j]) {
        return (s1[i]+lcs(s1,s2,i+1,j+1));
    }else {
        return max(lcs(s1,s2,i,j+1),lcs(s1,s2,i+1,j));
    }
}

struct rect{
    int length;
    int width;
};


int main()
{
    ifstream fin("packrec.in");
    rect rectArray[4];
    for(int i=0;i<4;++i){
        fin>>rectArray[i].length;
        fin>>rectArray[i].width;
    }
    return 0;
}
