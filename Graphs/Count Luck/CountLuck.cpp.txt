#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>
#include <string>
#include <climits>
#include <iomanip>
using namespace std;
int d1[4]={0,0,1,-1};
int d2[4]={1,-1,0,0};


bool check(int x,int y,char Graph[][200],bool visitet[][200]){
    int out=0;
    for(int i=0;i<4;i++){
        int nextX,nextY;
        nextX= x+d1[i];nextY= y+d2[i];
        if((Graph[nextX][nextY]=='.' || Graph[nextX][nextY]=='*') && !visitet[nextX][nextY])out++;
    }
   
    if(out>1)return true;
    return false;

}





int main()
{
    int cases;cin>>cases;
    while(cases--){
      int res,m,n,k;
      bool visitet[200][200]={{0}};
      char Graph[200][200]={{'X'}};

        int x,y;
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char s;cin>>s;
                Graph[i][j]=s;
                if(s=='M'){
                    x=i;y=j;
                }
            }
        }


        cin>>k;

        queue<pair<pair<int,int>,int>>q;
        q.push(make_pair(make_pair(x,y),0));
        visitet[x][y]=1;

        while(!q.empty()){

            pair<pair<int,int>,int> temp= q.front();
            q.pop();

            int x=temp.first.first;
            int y=temp.first.second;
            res=temp.second;
             visitet[x][y]=1;
          
            if(Graph[x][y]=='*'){
           
                if(res==k)cout<<"Impressed\n";
                else cout<<"Oops!\n";
                break;
            }


            for(int i=0;i<4;i++){
                int nextX,nextY;
                nextX= x+d1[i];nextY= y+d2[i];
                if(Graph[nextX][nextY]=='.' || Graph[nextX][nextY]=='*'){

                    if(!visitet[nextX][nextY]){

                        if (check(x,y,Graph,visitet))q.push(make_pair(make_pair(nextX,nextY),res+1));
                        else q.push(make_pair(make_pair(nextX,nextY),res));


                    }
                }
            }
        }
    }
}



