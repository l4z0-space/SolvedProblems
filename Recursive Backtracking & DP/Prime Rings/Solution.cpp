#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n;
vector<int>nums;
map<int, bool>used;

bool isPrime(int n) {
	if (n == 1)return false;
	if (n == 2) return true;
	if (n % 2 == 0)return false;
	for (int i = 3; i <= sqrt(n); i+=2) {
		if (n%i == 0)return false;
	}
	return true;
}

void show() {
	cout << 1;
	for (int i = 1; i < n; i++) {
		if (i <= n - 1)cout << " ";
		cout << nums[i];
	}
	cout << endl;
}

void solve(int currPos) {

	if (currPos == n - 1)
		if (isPrime(nums[currPos] + nums[0])) {
			show();
		}
	for (int i = 2 ; i <= n; i++) {

		if (isPrime(nums[currPos] + i)) {
			if (!used[i]) {
				used[i] = 1;
				nums.push_back(i);
				solve(currPos + 1);
				used[i] = 0;
				nums.pop_back();
			}
		}
	}
}



int main()
{
	int cnt = 1;
	while (cin >> n) {
		nums.clear();
		used.clear();
		nums.push_back(1);
		used[1] = 1;
		cout << "Case " << cnt << ":\n";
		solve(0);
		cnt++;
	}
}