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
map<int,vi>Graph;
int n,q;
vector<bool>visited(n,0);

void dfs(int start){
    visited[start]=1;
    for(int i=0;i<(int)Graph[start].size();i++){
        if(!visited[Graph[start][i]]) dfs(Graph[start][i]);
    }
}

int main(){

    int cases;
    cin>>cases;
    while(cases--){

        vi students;
        cin>>n>>q;
        while(q--){
            int a,b;
            cin>>a>>b;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
        int result=0;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                result++;
                dfs(i);
            }
        }

        cout<<result<<endl;
        visited.assign(n,0);
        Graph.clear();
    }

}
