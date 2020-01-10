#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int INF = 1000000000;

int goDijkstra(map<int,vii>AdjList,int start,int target){

    vi Distace(99999,INF);
    priority_queue<pii,vii,greater<pii>>pq;
    pq.push(pii(0,start)); // push the start element in Pqueue
    Distace[start]=0;


    while(!pq.empty()){

        pii currEl= pq.top();pq.pop();

        int currNode,currLatency;
        currNode = currEl.second;   // assigns the current latency and node
        currLatency = currEl.first;

        if(currLatency>Distace[currNode])continue;  // important check

        for(int i=0;i<(int)AdjList[currNode].size();i++){   // iterate through all neighbors

            pii next = AdjList[currNode][i];
            int nextNode=next.second;       // assigns next latency and node
            int nextLatency=next.first;

            int toUpdateLatency = Distace[currNode]+nextLatency;    // new latency

            if(toUpdateLatency < Distace[nextNode]){
                Distace[nextNode]= toUpdateLatency;     // relaxation operation
                pq.push(pii(nextLatency,nextNode));
            }
        }
    }
    return Distace[target]; // returns the minimal latency needed
}


int getInput(){

    map<int,vii>AdjList;
    int nServers,mCables,start,target;
    cin >> nServers >> mCables >> start >> target;
    int one,two,latency;
    while(mCables--){
        cin>>one>>two>>latency;
        AdjList[one].push_back(pii(latency,two));
        AdjList[two].push_back(pii(latency,one));
    }

    return goDijkstra(AdjList,start,target);
}




int main(){

    int cases;cin>>cases;
    for(int i=1;i<=cases;i++){
        int sol = getInput();

        cout<<"Case #"<<i<<": ";

        if(sol==INF)cout<<"unreachable";
        else cout<<sol;

        cout<<endl;
    }


}
