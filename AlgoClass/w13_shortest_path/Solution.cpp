#include <bits/stdc++.h>
#include <algorithm>
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

map <int,vi>graph;


int main() {

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;
    cin >> n >> m;

    forn(i,m){ 
        int a,b;
        cin >> a >> b;

        graph[a].pb(b);
        graph[b].pb(a);
    }

    queue< pair <int,int> > q;

    q.push(pii(1,0));

    bool used[100]={0};
    used[1] = 1;
    while(!q.empty()){

        int curr = q.front().first;
        int len = q.front().second;
        q.pop();

        if( curr == n ){
            cout << len + 1;
            return 0;
        }

        for(int nxt: graph[curr]){
                if(!used[nxt]){
                    used[nxt] = 1;
                    q.push( pii(nxt,len+1) );
                }
        }

    }
    cout << 0;
    return 0;
}
