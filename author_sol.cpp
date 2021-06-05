#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// based on observation, there are only up to two repeating sequences
	if (k % 2 == 1) {
		k = 1;
	} else if (k % 2 == 0 && k != 0) {
		k = 2;
	}
	for (int i = 0; i < k; i++) {
		long long mx = a[0];
		// find the maximum value in the current sequence
		for (int j = 1; j < n; j++) {
			mx = max(mx, a[j]);
		}
		// set every element equal to the difference of the maximum and current value
		for (int j = 0; j < n; j++) {
			a[j] = mx - a[j];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << '\n';
	return 0;
}
