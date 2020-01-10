#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>	// lazo99 * uhunt
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
map<string,bool>used;

int main(){

    int cases;cin>>cases;
    while(cases--){
        int i;cin>>i;
        while(i--){
            string a,b;
            cin>>a>>b;
            if(!used[a]){
                used[a]=1;
                r[a]=1;
                p[a]=a;
                sizeOfSets[a]=1;
            }

            if(!used[b]){
                used[b]=1;
                r[b]=1;
                p[b]=b;
                sizeOfSets[b]=1;
            }
            unionSet(a,b);
            cout<<sizeOfSets[findSet(a)]<<endl;

        }
        p.clear();
        r.clear();
        used.clear();
        sizeOfSets.clear();

    }
}
