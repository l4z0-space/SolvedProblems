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

                p[y]=x;
        }
        else{

            p[x]=y;
            if(r[x]==r[y])r[y]++;
        }

    }
}
map<int,bool>used;

int main(){

    int cases;
    scanf("%d", &cases);
    for(int qq=0;qq<cases;qq++){
        int i;
        scanf("%d",&i);
        getchar();
        int c=0,w=0;
        for(int e=1;e<=i;e++){
            r[e]=0;
            p[e]=e;
        }
        char a;
        int x,y;
        while((a=getchar()) && isalpha(a)){
            scanf("%d %d", &x,&y);getchar();
            if(a=='c')unionSet(x,y);
            if(a=='q'){
                if(SameSet(x,y))c++;
                else w++;
            }
        }
        cout<<c<<","<<w<<endl;
        if(qq!=cases-1)cout<<endl;
    }
}





