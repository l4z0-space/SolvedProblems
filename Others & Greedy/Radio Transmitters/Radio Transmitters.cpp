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

int main() {

  vector<bool> city(100000, 0);
  int n, k;
  cin >> n >> k;
  k = 2 * k;
  int u = 0;
  while (n--) {
    int a;
    cin >> a;
    city[a] = 1;
    u = max(u, a);
  }

  int result = 0;
  for (int i = 1; i <= u; i++) {
    if (city[i] == 1) {
      result++;
      int adder = k;
      for (int q = i + (k / 2); q >= i; q--) {
        if (city[q] == 1) {
          i += adder;
          break;
        } else
          adder--;
      }
    }
  }
  cout << result;
}