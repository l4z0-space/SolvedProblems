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
vector<pair<int,int>>Board;
vector<pair<int,int>>Sol;
pair<int,int> first,last;
int n,m,a1,a2,a3,a4;
vector<bool>visited(1000,0);
bool solved=0;



void bTrack(int pos,int a){

    if(pos==n) if (Sol[pos].second==a)solved=1;


    for(int i=0;i<=m;i++){


            if(Board[i].first==Sol[pos].second && !visited[i]) {
                visited[i]=1;
                Sol.push_back(Board[i]);

                bTrack(pos+1,a);
                Sol.pop_back();
                visited[i]=0;
            }
            else if(Board[i].second==Sol[pos].second && !visited[i]){
                visited[i]=1;
                swap(Board[i].second,Board[i].first);
                Sol.push_back(Board[i]);

                bTrack(pos+1,a);
                Sol.pop_back();
                visited[i]=0;
            }
    }
}


int main(){


   while( cin >>n && n!=0){
        cin>>m;
        pair<int,int>first,last;
        int a1,a2;cin>>a1>>a2;


        first=make_pair(a1,a2);
        cin>>a3>>a4;
        last=make_pair(a3,a4);
        int a = last.first;

        Board.push_back(first);

        for(int i=0;i<m;i++){
            cin>>a1>>a2;
            Board.push_back(make_pair(a1,a2));
        }

        Sol.push_back(first);
        visited[0]=1;

        bTrack(0,a);
        if(solved)cout<<"YES\n";
        else cout<<"NO\n";
        solved=0;

        visited.clear();
        Sol.clear();
        Board.clear();
        visited.assign(100,0);

}

}



