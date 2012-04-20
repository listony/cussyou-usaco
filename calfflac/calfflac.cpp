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
// ignore case
bool compNode( char* array, node a, node b)
{
    if((a.end-a.start) != (b.end-b.start)){
        return false;
    }
    int len = a.end-a.start;
    for(int i=0;i<len;i++){
        if(array[a.start+i] != array[b.start+i]) return false;
    }
    return true;
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
    ifstream fin("calfflac.in");
    inputSize =0;
    while(!fin.eof()){
        fin>>input[inputSize];
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
    int k=0;
    bool unit = false; // whether unit 2 or 3 node into 1
    while(k<arraySize||unit){
        unit = false;
        if(palnSize>2){
            bool ret = compNode(charArray,palnArray[palnSize-3],palnArray[palnSize-1]);
            if(ret){
                unit=true;
                palnArray[palnSize-3].end=palnArray[palnSize-1].end;
                palnSize=palnSize-2;
            }else{
                unit=false;
            }
        }
        if(palnSize>1){
             bool ret = compNode(charArray,palnArray[palnSize-2],palnArray[palnSize-1]);
             if(ret){
                 unit=true;
                 palnArray[palnSize-2].end=palnArray[palnSize-1].end;
                palnSize=palnSize-1;
             }else{
                 unit=false;
             }
        }
        if(!unit){ // forward a new node
            palnArray[palnSize].end=k+1;
            palnArray[palnSize].start=k;
            ++k;
            ++palnSize;
        }
    }
    int max=0;
    int maxIndx=0;
    for(int i=0;i<palnSize;++i){
        int tmpMax=palnArray[i].end-palnArray[i].start;
        if(tmpMax>max){
            max=tmpMax;
            maxIndx=i;
        }
    }
    ofstream fout("calfflac.out");
    fout<<max<<endl;
    for(int i=charPosition[palnArray[maxIndx].start];i<charPosition[palnArray[maxIndx].end];++i){
        fout<<input[i];
    }
    fout<<endl;
    return 0;
}
