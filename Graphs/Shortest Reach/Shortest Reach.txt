#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int n, m;
map<int, vector<int>> City;
vector<int> visited;
vector<bool> vis;

int main() {

  int cases;
  cin >> cases;
  while (cases--) {

    cin >> n >> m;
    visited.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    while (m--) {
      int a, b;
      cin >> a >> b;
      City[a].push_back(b);
      City[b].push_back(a);
    }
    int start;
    cin >> start;

    queue<pair<int, int>> Q;
    Q.push(make_pair(start, 0));

    while (!Q.empty()) {

      pair<int, int> v = Q.front(), temp;
      Q.pop();

      for (int i = 0; i < (int)City[v.first].size(); i++) {
        temp = make_pair(City[v.first][i], v.second + 1);
        if (!vis[temp.first]) {
          vis[temp.first] = 1;
          visited[temp.first] = temp.second;
          Q.push(temp);
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      if (visited[i] == 0)
        visited[i] = -1;
      else
        visited[i] *= 6;
    }
    for (int i = 1; i <= n; i++) {
      if (i != start)
        cout << visited[i] << " ";
    }

    cout << endl;

    City.clear();
    visited.clear();
    vis.clear();
  }
}
