#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#include <tuple>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
#define print(a)            cout<<a;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<pii,int>ppi;
typedef vector<pii>vp;


vp allXY[105],allXZ[105];


int main(){


   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,z;
    int maxNumber=0;
    int minNumber=0;
    cin>>x>>y>>z;

    int XYcounter[x];
    forn(i,x){
        int cnt=0;
        forn(j,y){
            char nxt;cin>>nxt;
            if(nxt=='1')cnt++,allXY[i].pb(pii(i,j));
        }XYcounter[i]=cnt;
    }

    forn(i,x){
        int cnt=0;
        forn(j,z){
            char nxt;cin>>nxt;
            if(nxt=='1')cnt++,allXZ[i].pb(pii(i,j));
        }
        if(cnt==0 && XYcounter[i]>0){cout<<-1;return 0;}
        if(cnt>0 && XYcounter[i]==0){cout<<-1;return 0;}
        minNumber+=max(cnt,XYcounter[i]);
        maxNumber+=(cnt*XYcounter[i]);

    }


    cout<<maxNumber<<"\n";

    forn(i,x){
        vp ys =allXY[i];
        vp zs =allXZ[i];
        for(pii yy:ys){
            for(pii zz:zs)cout<<i<<" "<<yy.second<<" "<<zz.second<<"\n";
        }
    }
    cout<<minNumber<<"\n";

    forn(i,x){
        vp ys=allXY[i];
        vp zs=allXZ[i];
        int P = (int)ys.size();
        int Q = (int)zs.size();
        if(P>Q)for(;Q<P;Q++)zs.pb(pii(i,zs[0].second));
        else if(P<Q)for(;P<Q;P++)ys.pb(pii(i,ys[0].second));
        sorted(ys);sorted(zs);


        forn(it,Q)cout<<i<<" "<<ys[it].second<<" "<<zs[it].second<<"\n";

    }return 0;


}



