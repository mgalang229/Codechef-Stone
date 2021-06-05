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
	// find the maximum in the original sequence
	long long mx = *max_element(a.begin(), a.end());
	// create a first version wherein the original maximum is subtracted in the elements
	vector<long long> first_version = a;
	for (int i = 0; i < n; i++) {
		first_version[i] = mx - first_version[i];
	}
	// also, create a second version wherein the first version's maximum is subtracted in the elements
	long long first_version_mx = *max_element(first_version.begin(), first_version.end());
	vector<long long> second_version = first_version;
	for (int i = 0; i < n; i++) {
		second_version[i] = first_version_mx - second_version[i];
	}
	for (int i = 0; i < n; i++) {
		if (k == 0) {
			// if 'k' is equal to 0, then use the original sequence
			cout << a[i] << " ";
		} else if (k % 2 == 1) {
			// if 'k' is odd, then use the first version sequence
			cout << first_version[i] << " ";
		} else {
			// if 'k' is even, then use the second version sequence
			cout << second_version[i] << " ";
		}
	}
	cout << '\n';
	return 0;
}
