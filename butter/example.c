/*
ID: cussyou1
PROG: butter
LANG: C++
*/

#include <iostream>
#define L_MAX 1e6
using namespace std;
int N,P,C,cow[501],E[1451][4],e=1,d[801];
void init()
{
     cin>>N>>P>>C;
     for (int i=1;i<=N;i++)
         cin>>cow[i];
     for (int i=1;i<=C;i++) 
         cin>>E[i][1]>>E[i][2]>>E[i][3];
}
void Init_SS(int s)
{
     for (int i=1;i<=P;i++)
         d[i]=(int)L_MAX;
     d[s]=0;
}
bool relax(int u,int v,int x)
{
     if (d[v]>d[u]+x) {
                      d[v]=d[u]+x;
                      return true;
                      }
     return false;
}
void bellman(int s)
{
     Init_SS(s);
     for (int i=1;i<P;i++) {
         bool dosth=false;
         for (int j=1;j<=C;j++) 
             if (relax(E[j][1],E[j][2],E[j][3]) ||
                relax(E[j][2],E[j][1],E[j][3]) ) dosth=true;
         if (!dosth) return;
         }
}
void display()
{
     long ans=(int)L_MAX,sum;
     for (int k=1;k<=P;k++) {
         bellman(k);
         sum=0;
         for (int i=1;i<=N;i++) 
             sum+=d[cow[i]];
         if (sum<ans) ans=sum;
         }
     cout<<ans<<endl;
}
int main() 
{
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    init();
    display();
    return 0;
}
