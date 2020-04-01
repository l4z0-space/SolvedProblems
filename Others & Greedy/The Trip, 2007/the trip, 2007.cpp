#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <stdio.h>
#include <queue>
#include <thread>
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




int main() {


     //freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);

    int n;
    while(cin>>n){
        if(n==0)break;

        vi all(n);
        unordered_map<int,int>freq;
        int mxFreq=0;
        forn(i,n){
            cin>>all[i];
            freq[all[i]]++;
            mxFreq = max(mxFreq,freq[all[i]]);

        }


        vii pairs;


        unordered_map<int,bool>used;

        for(int x: all){
            if(!used[x]){
                used[x]=1;
                pairs.pb(pii(freq[x],x));
            }
        }

        sorted(pairs);

        vector<vi> solutions(mxFreq);
        int it=0;
        for(int i=0;i<(int)pairs.size();i++){
                for(int j=0;j<pairs[i].first;j++){
                    solutions[it%mxFreq].push_back(pairs[i].second);
                    it++;

                }
        }
        cout<<mxFreq<<endl;
        for(int i=0;i<mxFreq;i++){sorted(solutions[i]);
            for(int j=0;j<solutions[i].size();j++){
                cout<<solutions[i][j];
                if(j!= solutions[i].size()-1)cout<<" ";
            }cout<<endl;
        }
        cout<<endl;
}
}









