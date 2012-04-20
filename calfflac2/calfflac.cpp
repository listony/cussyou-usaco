/*
ID: cussyou1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int const MaxOfStr=20000;
struct node{
    int start;
    int end;
};
void extend(char *array, int size,node & a)
{
    int i,j;
    i=a.start-1;
    j=a.end+1;
    while((i>=0)&&(j<size)){
        if(array[i]!=array[j]) break;
        a.start=i;
        a.end=j;
        --i;
        ++j;
    }
}
int main()
{
    // all varibles
    char input[MaxOfStr];
    int inputSize;
    // save the real charector only a-z A-Z
    char charArray[MaxOfStr];
    // save the position of every char in the orignal input string
    int charPosition[MaxOfStr];
    int arraySize;
    node palnArray[MaxOfStr];
    int palnSize;

    // read all
    ifstream fin("calfflac.in",ios::binary | ios::in);
    inputSize =0;
    while(!fin.eof()){
        fin.get(input[inputSize]);
        ++inputSize;
    }
    // transform
    arraySize=0;
    for(int i=0;i<inputSize;++i){
        if(((input[i]>='a')&&(input[i]<='z'))||((input[i]>='A')&&(input[i]<='Z'))){
            if((input[i]>='A')&&(input[i]<='Z')){
                charArray[arraySize]=input[i]-'A'+'a';
            }else{
                charArray[arraySize]=input[i];
            }
            charPosition[arraySize]=i;
            ++arraySize;
        }
    }
    // ok, let's go
    palnSize=0;
    for(int i=1;i<arraySize-1;++i){
        if(charArray[i+1]==charArray[i-1]){
            palnArray[palnSize].start=i-1;
            palnArray[palnSize].end=i+1;
            palnSize++;
            continue;
        }
        if(charArray[i+1]==charArray[i]){
            palnArray[palnSize].start=i;
            palnArray[palnSize].end=i+1;
            palnSize++;
            continue;
        }
    }
    // extend ...
    for(int i=0;i<palnSize;++i){
        extend(charArray,arraySize, palnArray[i]);
    }
    int max=0;
    int maxIndx=0;
    for(int i=0;i<palnSize;++i){
        int tmpMax=palnArray[i].end-palnArray[i].start+1;
        if(tmpMax>max){
            max=tmpMax;
            maxIndx=i;
        }
    }
    ofstream fout("calfflac.out",ios::binary);
    fout<<max<<endl;
    for(int i=charPosition[palnArray[maxIndx].start];i<=charPosition[palnArray[maxIndx].end];++i){
        fout<<input[i];
    }
    fout<<endl;
    return 0;
}
