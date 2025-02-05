using namespace std;
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	vector<int> vals = {11, 13, 16, 16, 16, 24, 30, 30, 39, 45, 48, 67};

	sort(all(vals)); //introSort
	
	cout << (lower_bound(all(vals), 16) - vals.begin());
	cout << (lower_bound(all(vals), 35) - vals.begin());
	cout << (upper_bound(all(vals), 16) - vals.begin());
	cout << (lower_bound(all(vals), 100) - vals.begin());
}
