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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<char>vch;
typedef vector<bool>vb;
typedef map<int,vi>alist;
typedef map<string,int>msi;
typedef map<string,string>mss;
int allSets;
vi p(100000,0);
vi r(100000,0);



int findSet(int a){
    if(p[a]==a)return a;
    else return (p[a]=findSet(p[a]));
}

bool SameSet(int a, int b){
    return findSet(a)==findSet(b);
}

void unionSet(int a, int b){
    if(!SameSet(a,b)){
        allSets--;
        int x = findSet(a);
        int y = findSet(b);

        if(r[x]>r[y]){p[y]=x;}
        else{
            p[x]=y;
            if(r[x]==r[y])r[y]++;
        }
    }
}
map<int,bool>used;

int main(){
    int cnt=1;
    int total,queries;

    while(cin>>total>>queries){

        allSets=total;
        if(total==0 && queries==0)break;

        for(int i=1;i<=total;i++){
            r[i]=0;
            p[i]=i;
        }

        int result=0;
        while(queries--){
            int a,b;
            cin>>a>>b;

            if(a<=total && a>=1)if(b<=total && b>=1) unionSet(a,b);
        }
        for(int i=1;i<=total;i++){
            if(!used[p[i]]){
                used[p[i]]=1;
            }
        }
        cout<< "Case " << cnt++ << ": " << allSets <<endl;
        p.clear();
        r.clear();
        used.clear();

    }
}





