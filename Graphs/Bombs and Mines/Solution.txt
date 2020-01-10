#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<char>vch;
typedef vector<bool>vb;
typedef map<int,vi>alist;
typedef map<string,int>msi;
typedef map<string,string>mss;
typedef map<pii,int>mpi;

int d1[4]={0,0,1,-1};
int d2[4]={1,-1,0,0};
bool grid[5000][5000]={0};

int x,y;

bool safe(int a,int b){
    if(a<0 || a>=x || b<0 || b>=y)return false;
    return true;
}

int main(){

    int nrRows;
    while(cin>>x>>y){

         for(int i=0;i<2000;i++){
            for(int j=0;j<2000;j++)grid[i][j]=0;
        }
        if(x==0 && y==0)break;
        cin>>nrRows;


        while(nrRows--){

            int r,nC;
            cin>>r>>nC;
            while(nC--){
                int a;cin>>a;

                grid[r][a]=1;
            }
        }

        int stX,stY,enX,enY;
        cin>>stX>>stY>>enX>>enY;
        queue<pair<pii,int>>q;
        q.push(make_pair(pii(stX,stY),0));
        while(!q.empty()){

            int currX=q.front().first.first;
            int currY=q.front().first.second;
            int dist=q.front().second;
            //cout<<currX<<" "<<currY<<" ->"<<dist<<endl;
            q.pop();
            grid[currX][currY]=1;
            if(currX==enX && currY==enY){cout<<dist<<endl;break;}

            for(int i=0;i<4;i++){
                int nxX=currX+d1[i];
                int nxY=currY+d2[i];
                if(!grid[nxX][nxY] && safe(nxX,nxY)){
                    grid[nxX][nxY]=1;
                    q.push(make_pair(pii(nxX,nxY),dist+1));
                }
            }

        }


    }


}




