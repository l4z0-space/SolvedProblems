#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <map>
#include <string>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
//int INF =1e9;
int n;
int grid[10][10];
map<int,bool> uROW, uCOL;

int RESULT=1e9;

void COLS(int col, int row, int sum ){

    if(row==n-1)RESULT=min(RESULT,sum);

    forn(col,n){
        if(!uCOL[col]){
            uCOL[col]=1;
            COLS(col,row+1,sum+grid[row+1][col]);
            uCOL[col]=0;
        }
    }
}




int main(){
    //ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
    int tc;cin>>tc;
    while(tc--){
        RESULT=1e9;
        cin>>n;
        uCOL.clear();uROW.clear();
        forn(i,n)forn(j,n)cin>>grid[i][j];
        forn(o,n)uCOL.clear(),uCOL[o]=1,COLS(o,0,grid[0][o]);
        cout<<RESULT<<endl;

    }





}
