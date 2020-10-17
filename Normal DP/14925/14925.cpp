#include<iostream>
#include<algorithm>
using namespace std;
int M, N;
char mp[1000][1000];
int dp[1000][1000];
int mx = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || j == 0) {
				if (mp[i][j] == '0') {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
				}
			}
			else {
				if (mp[i][j] == '0') {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
				else {
					dp[i][j] = 0;
				}
			}
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx;
	return 0;
}