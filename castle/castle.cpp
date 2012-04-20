/*
ID: cussyou1
PROG: castle
LANG: C++
*/

#include <fstream>

using namespace std;

const int MaxSize = 50;

enum{
    Wwest=1;
    Wnorth=2;
    Weast=4;
    Wsouth=8;
};
struct node{
    int colored;
    int wall;
    int roomColor;
};

// save the every
node roomTable[MaxSize][MaxSize];
int width,length;

// save every room's size
int roomArray[MaxSize*MaxSize];
int roomNum=0;

void number(int color, int x, int y)
{
    if(roomTable[x][y].colored
    roomTable[x][y].roomColor=color;
    ++roomArray[roomNum];
    if((x>0)&&(roomTable[x][y]&Wwest)&&(roomTable[x-1][y].color==-1)){
        number(color,x-1,y);
    }
    if((x<length-1)&&(roomTable[x][y]
}

int main()
{
	// init table
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	// read all

	fin>>width>>length;
    for(int i=0;i<length;++i){
        for(int j=0;j<width;++j){
            roomTable[i][j].roomColor=-1;
            fin>>roomTable[i][j].wall;
        }
    }
    // find room number
    for(int i=0;i<length;++i){
        for(int j=0;j<width;++j){
            if(roomTable[i][j].roomColor==-1){
            }
        }
    }
	return 0;
}
