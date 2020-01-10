#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>			// classic flood filling problem (just graph traversal)
using namespace std;

int d1[8]={1,1,1,-1,-1,-1,0,0};
int d2[8]={1,-1,0,1,-1,0,1,-1};
int A[12][12]={{0}};

int dfs(int x,int y){
    if (A[x][y]==0)return 0; 
    A[x][y]=0;
    int ans=1;
    for ( int i= 0 ; i<8;i++){ans+= dfs(x+d1[i],y+d2[i]);} 	//explore connected cells
    return ans;}

int main(){
    int result=0;
    int m,n;cin>>m>>n;

    for (int i=1;i<=m;i++){for(int j=1;j<=n;j++)cin>>A[i][j];}
    for ( int i=1;i<=m;i++){for (int j=1;j<=n;j++){
            if(A[i][j]==1){result=max(result,dfs(i,j));}}}
    cout <<result<<endl;
}
