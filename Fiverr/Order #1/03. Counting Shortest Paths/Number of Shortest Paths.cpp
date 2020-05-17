#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> Graph;

int main() {

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nEdges, nNodes;
    int start, target;

    cin >> nEdges >> nNodes >> start >> target;

    /*  Build the Graph  */
    for( int i = 0; i < nEdges; i++ ){
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    int Distance[nEdges];
    int Paths[nEdges];
    bool Visited[nEdges];

    /*  Assign the default values to the arrays  */

    for(int i = 1; i <= nNodes ; i++ ){
        Distance[i] = 100000;
        Paths[i] = 0;
        Visited[i] = false;
    }

    /*  Run BFS  */

    queue< int > Q;
    Q.push(start);
    Visited[start] = true;
    Paths[start] = 1;
    Distance[start] = 0;
    while( !Q.empty() ){

        int current = Q.front();
        Q.pop();
        for( int x : Graph[current] ){

            if( Visited[x] == 0 ){
                Q.push(x);
                Visited[x] = 1;
            }

            if( Distance[x] > Distance[current] + 1 ){
                Distance[x] = Distance[current] + 1;
                Paths[x] = Paths[current];
            }

            else if( Distance[x] == Distance[current] + 1 ){
                Paths[x] += Paths[current];
            }
        }
    }
    cout << "L(start, target): " << Distance[target] << endl;
    cout << "Number of shortest paths from " << start << " to " << target << ": " << Paths[target];

}

/* Input Format

numEdges numVertices
start target

edge
edge
...

*/



/* Sample input

10 8

1 8

1 2
1 3
1 4
2 5
3 5
4 5
5 6
5 7
6 8
7 8


  Sample Output
L(start, target) 4
Number of shortest paths from 1 to 8: 6


*/


