#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
#include <istream>
#include <unordered_set>
#include <stdio.h>
#include <string.h>
#include <list>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
map<int,vi>city;
map<pii,int>costs;
map<int,int>counter;
map<int,bool>visited;
int minCost;


void findShortest(int start,int cost,int finish){

    if(start==finish){
        minCost=min(minCost,cost);
        counter[cost]++;
        return;
    }

    for(int i=0;i<(int)city[start].size();i++){
        int next=city[start][i];
        if(!visited[next]){
            visited[next]=1;
            findShortest(next,cost+costs[pii(start,next)],finish);
            visited[next]=0;
        }
    }
}

int solve(){
    city.clear();
    visited.clear();
    counter.clear();
    costs.clear();
    minCost=100000;

    int N,M;
    cin>>N>>M;
    while(M--){
        int a,b,l;
        cin>>a>>b>>l;
        costs[pii(a,b)]=l;
        costs[pii(b,a)]=l;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    visited[1]=1;
    findShortest(1,0,N);
    return counter[minCost];
}

int main(){

    int cases;
    cin>>cases;
    while(cases--)cout<<solve()<<endl;;


}
