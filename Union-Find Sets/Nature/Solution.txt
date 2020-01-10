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

msi sizeOfSets;
mss p;
msi r;



string findSet(string a){
    if(p[a]==a)return a;
    else return (p[a]=findSet(p[a]));
}

bool SameSet(string a, string b){
    return findSet(a)==findSet(b);
}

void unionSet(string a, string b){
    if(!SameSet(a,b)){
        string x = findSet(a);
        string y = findSet(b);

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


int main(){

    int total,queries;
    while(cin>>total>>queries){
        if(total==0 && queries==0)break;
        for(int i=1;i<=total;i++){
            string name;
            cin>>name;
            p[name]=name;
            r[name]=0;
            sizeOfSets[name]=1;
        }
        int result=1;
        while(queries--){
            string a,b;
            cin>>a>>b;
            unionSet(a,b);
            result=max(result,sizeOfSets[findSet(a)]);

        }

        cout<< result <<endl;
        p.clear();
        r.clear();

    }
}





