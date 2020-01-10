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

vi sizeOfSets(100000,0);
vi p(10000,0);
vi r(10000,0);



int findSet(int a){
    if(p[a]==a)return a;
    else return (p[a]=findSet(p[a]));
}

bool SameSet(int a, int b){
    return findSet(a)==findSet(b);
}

void unionSet(int a, int b){
    if(!SameSet(a,b)){
        int x = findSet(a);
        int y = findSet(b);

        if(r[x]>r[y]){
                sizeOfSets[findSet(x)]+=sizeOfSets[findSet(y)];
                p[y]=x;
        }
        else{
            sizeOfSets[findSet(y)]+=sizeOfSets[findSet(x)];
            p[x]=y;
            if(r[x]==r[y])r[y]++;
        }

    }
}
map<int,bool>used;

int main(){

    int cases;cin>>cases;
    while(cases--){
        int total,queries;
        cin>>total>>queries;
        for(int i=1;i<=total;i++){
            r[i]=0;
            p[i]=i;
            sizeOfSets[i]=1;
        }
        int result=1;
        while(queries--){
            int a,b;
            cin>>a>>b;
            unionSet(a,b);
            result=max(result,sizeOfSets[findSet(a)]);
        }
        cout<<result<<endl;

    }
}





