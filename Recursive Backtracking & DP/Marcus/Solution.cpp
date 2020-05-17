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
#include <cstring>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
int res=0;
map<int,vi>graph;

int n,m;
vector<string>result;

string check="@IEHOVA#";



void show(){
    int sz=(int)result.size()-1;
    for(int i=0;i<=sz;i++){
        if(i!=sz)cout<<result[i]<<" ";
        else cout<<result[i]<<endl;
    }
}

void btrack(string temp,int nextChar,int x,int y, char a[][15] , bool used[][15] ){
    //cout<<temp<<endl;
    if( temp == check){show();return;}

    if(  a[x-1][y] == check[nextChar] && !used[x-1][y] ){
        used[x-1][y]=1;
        result.push_back("forth");
        btrack(temp+check[nextChar],nextChar+1,x-1,y,a,used);
        result.pop_back();
        used[x-1][y]=0;
    }

    if(  a[x][y-1] == check[nextChar] && !used[x][y-1] ){
        used[x][y-1]=1;
        result.push_back("left");
        btrack(temp+check[nextChar],nextChar+1,x,y-1,a,used);
        result.pop_back();
        used[x][y-1]=0;
    }

    if(  a[x][y+1] == check[nextChar] && !used[x][y+1] ){
        used[x][y+1]=1;
        result.push_back("right");
        btrack(temp+check[nextChar],nextChar+1,x,y+1,a,used);
        result.pop_back();
        used[x][y+1]=0;
    }

}



int main(){
    int c;cin>>c;
    while(c--){
        result.clear();
        char a[15][15];
        bool used[15][15];
        cin>>n>>m;

        int sx,sy;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='@'){sx=i;sy=j;}
            }
        }

        btrack("@",1,sx,sy,a,used);
    }
}

