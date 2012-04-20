/*
ID: cussyou1
PROG: holstein
LANG: C++
*/

#include <fstream>
#include <list>

using namespace std;

const int MaxNum = 25;
struct Feed{
	int vtm[MaxNum];
	char feedType[15];
	char ptr; // 0..14
};
Feed feedArray[15];
int feedNum=0;

int minVtm[MaxNum];
int vtmNum;

int main()
{
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	// read
	fin>>vtmNum;
	for(int i=0;i<vtmNum;++i){
		fin>>minVtm[i];
	}
	fin>>feedNum;
	for(int i=0;i<feedNum;++i){
		for(int j=0;j<vtmNum;++j){
			fin>>feedArray[i].vtm[j];
			for(int k=0;k<feedNum;++k) feedArray[i].feedType[k]=0;
			feedArray[i].ptr=i;
			feedArray[i].feedType[i]=1;
		}
	}
	//
	Feed result;
	list<Feed> feedStack;
	for(int i=0;i<feedNum;++i){
		feedStack.push_back(feedArray[i]);
	}
	while(!feedStack.empty()){
		Feed tmp = feedStack.front();
		feedStack.pop_front();
		// check
		bool isEnough=true;
		for(int i=0;i<vtmNum;++i){
			if(tmp.vtm[i]<minVtm[i]){
				isEnough=false;
				break;
			}
		}
		if(isEnough){
			result=tmp;
			break;
		}
		if(tmp.ptr<feedNum-1){ // add children
			for(int i=tmp.ptr+1;i<feedNum;++i){
				Feed tmp2=tmp;
				tmp2.feedType[i]=1;
				tmp2.ptr=i;
				for(int k=0;k<vtmNum;++k){
					tmp2.vtm[k]+=feedArray[i].vtm[k];
				}
				feedStack.push_back(tmp2);
			}
		}
	}
	// output
	int num=0;
	for(int i=0;i<feedNum;++i){
		if(result.feedType[i]==1) ++num;
	}
	fout<<num<<" ";
	int counter=0;
	for(int i=0;i<feedNum;++i){
		if(result.feedType[i]==1){
			counter++;
			if(counter<=num-1){
				fout<<i+1<<" ";
			}else 
				break;
		}
	}
	/*
	for(int i=feedNum-1;i>=0;--i){
		if(result.feedType[i]==1){
			fout<<i+1<<endl;
			break;
		}
	}
	*/
	fout<<result.ptr+1<<endl;
	return 0;
}
