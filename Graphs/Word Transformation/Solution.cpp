#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;



bool safe(string a, string b){

    int lenA=(int)a.length();
    int lenB=(int)b.length();

    int result=0;
    if(lenA==lenB){
        for(int i=0;i<lenA;i++)
                if(a[i]!=b[i])result++;
        if(result==1){
            return true;
        }
    }return false;
}


typedef pair<string,int>psi;
int goBfs(string start, string target, vector<string>all){

    int toReturn;
    queue<psi>q;
    q.push(psi(start,0));
    map<string,bool>used;
    used[start]=1;
    while(!q.empty()){
        psi currNode=q.front();q.pop();
        string currString = currNode.first;
        int Path = currNode.second;
        if(currString==target){toReturn=Path;break;}

        for(int i=0;i<(int)all.size();i++){
            string next=all[i];
            if(!used[next] && safe(currString,next)){
                used[next]=1;
                q.push(psi(next,Path+1));
            }
        }
    }
    return toReturn;
}


void solve(){

    vector<string>all;
    string next;
    while(cin>>next && next!="*"){
        all.push_back(next);
    }
    string start,target;
    string line;

    cin.ignore(1,'\n');
    while(getline(cin,line) && line.length()!=0){
        stringstream ss(line);
        ss >> start >> target;
        int result=goBfs(start,target,all);

        cout<<start<<" "<<target<<" "<<result<<endl;
    }

}

int main(){

    int cases;cin>>cases;
    for(int i=1;i<=cases;i++){
        if(i==cases)solve();
        else{solve();cout<<endl;}
    }
}
