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
map<int,vector<int>>Graph;
int target,total;
bool found=0;

void dfs(int curr,int sum){
    if(curr==total+1){
        if(sum<=target){cout<<sum<<endl;found=1;return;}
        else return;
    }
    else{
        for(int i=0;i<(int)Graph[curr].size();i++){

            if(!found)dfs(curr+1,sum+Graph[curr][i]);
        }
    }
}

int main(){

    int cases;cin>>cases;
    while(cases--){
        cin>>target>>total;
        for(int mp=1;mp<=total;mp++){
            int n;cin>>n;
            vector<int>temp;
            while(n--){int a;cin>>a;temp.push_back(a);}
            sort(temp.begin(),temp.end(),greater<int>());
            Graph[mp]=temp;
        }
        dfs(1,0);
        if(!found)cout<<"no solution\n";
        Graph.clear();
        found=0;
    }
}
