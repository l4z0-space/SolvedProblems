// **Lazaron Shyta Uhunt: lazo99
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <fstream>
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
typedef long long  ll;



int main(){


    map<char,pair<int,int>>moves;

    moves['N']=make_pair(-1,0);
    moves['W']=make_pair(0,-1);
    moves['E']=make_pair(0,1);
    moves['S']=make_pair(1,0);

    int x,y,x1;
    while(cin>>x>>y>>x1 && x!=0){

        map<pair<int,int>,bool>visited;
        char grid[20][20];
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>grid[i][j];
            }
        }
        int step[20][20];


        pair<int,int>curr = make_pair(1,x1);
        visited[curr]=1;
        int steps=0;
        step[1][x1] = 0;

        while(true){
            int a,b;
            a= curr.first;b=curr.second;
            curr.first =  a + moves[grid[a][b]].first;
            curr.second = b + moves[grid[a][b]].second;
            if(curr.first > x || curr.second>y || curr.first <1 || curr.second<1){
                cout<< steps +1<< " step(s) to exit\n";
                break;
            }

            else if( visited[curr]){
                cout<< step[curr.first][curr.second] << " step(s) before a loop of " << steps - step[curr.first][curr.second] +1<<" step(s)\n";
                break;
            }

            else{
                    steps++;
                    visited[curr] =1;
                    step[curr.first][curr.second]=steps;
            }


        }





    }


}




