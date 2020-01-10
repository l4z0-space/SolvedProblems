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
typedef pair<string,int> pi;
typedef vector<pi> vsi;
typedef vector<vsi> BIG;
map<vsi,bool>visited;
int total,target;
vsi all;
BIG sol;
vsi temp;
map<int,int>Votes;
int minVotes=1000;

map<pair<string,int>,bool>used;

void btrack(int sum,int pos){

    sort(temp.begin(),temp.end());
    if(sum>=target && !visited[temp]){
            visited[temp]=1;
            sol.push_back(temp);
            minVotes=min(minVotes,sum);
            Votes[sum]++;
    }

    for(int i=pos;i<(int)all.size();i++){

        if(used[all[i]]!=1){
            temp.push_back(all[i]);
            used[all[i]]=1;
            btrack(sum+all[i].second,pos+1);
            temp.pop_back();
            used[all[i]]=0;
        }

    }
    return;
}

void show(vsi toShow){
    for(int i=0;i<(int)toShow.size();i++){
        cout<<toShow[i].first<<",";
    }cout<<endl;
}

int main(){

    int n;cin>>n;
    for(int i=0;i<n;i++){
        string a;int num;
        cin>>a>>num;
        total+=num;
        all.push_back(make_pair(a,num));
    }
    target=total/2;
    btrack(0,0);
    for(int i=0;i<(int)sol.size();i++){
        show(sol[i]);
    }
    cout<<sol.size()<<" "<<Votes[minVotes]<<endl;

}
