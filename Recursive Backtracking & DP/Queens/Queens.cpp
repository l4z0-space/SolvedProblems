#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef vector<int> vi;
int queens;
vi row(8);

void print(){
    cout<< "Possible arrangement:\n\n";

    for(int i=0;i<queens;i++){
        for(int j=0;j<queens;j++){
            if(row[i]==j)cout<< " Q ";
            else cout<< " _ ";
        }cout<<endl;
    }
    cout<<"\n\n";
}
bool safe(int a,int c){
    for(int i=0;i<c;i++){
        if(row[i]==a || abs(row[i]-a) == abs(i-c)){
            return false;
        }
    }return true;
}


void dfs(int c){

    if(c==queens){
            print();
            return;}

    else{
        for(int i=0;i<queens;i++){
            if(safe(i,c)){
                row[c]=i;
                dfs(c+1);

            }
        }
    }
}

int main(){

    cin>>queens;
    dfs(0);
}
