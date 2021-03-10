#include<iostream>
#include<algorithm>
using namespace std;
int N, c;
int bowl[50001];
int res = 0;
int main(void) {
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= 50000; i++) {
		bowl[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		bowl[c]++;
	}
	for (int i = 1; i <= 50000; i++) {
		res = max(res, bowl[i]);
	}
	cout << res;
	return 0;
}