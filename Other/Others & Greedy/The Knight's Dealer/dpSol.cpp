#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef long long ll;

map<int,vector<int>>Next;

void setNext(){
  Next[0]={4,6};
  Next[1]={6,8};
  Next[2]={7,9};
  Next[3]={4,8};
  Next[4]={3,9,0};
  Next[6]={1,7,0};
  Next[7]={6,2};
  Next[8]={1,3};
  Next[9]={2,4};
}

int main(){


  setNext();
  int dp[100][100]={0};
  int start,lvl;
  cin>>start>>lvl;
  dp[0][start]=1;

  for(int l=1;l<=lvl;l++){
    for(int num=0;num<10;num++){
      
        int sz=(int)Next[num].size();
        for(int i=0;i<sz;i++){
          dp[l][num]+=dp[l-1][Next[num][i]];
        
      }
    }
  }
  int result=0;
  for(int i=0;i<10;i++)result+=dp[lvl][i];

  cout<<result;
}
