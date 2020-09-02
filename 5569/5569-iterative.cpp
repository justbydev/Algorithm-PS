#include<iostream>
#define D 100000
using namespace std;
int w, h;
int dp[100][100][4];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> w >> h;
	for (int i = 1; i <= w - 1; i++) {
		dp[0][i][3] = 1;
	}
	for (int i = 1; i <= h - 1; i++) {
		dp[i][0][0] = 1;
	}
	for (int i = 1; i <= h - 1; i++) {
		for (int j = 1; j <= w - 1; j++) {
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % D;
			dp[i][j][1] = dp[i - 1][j][3];
			dp[i][j][2] = dp[i][j - 1][0];
			dp[i][j][3] = (dp[i][j - 1][2] + dp[i][j - 1][3]) % D;
		}
	}
	cout << (dp[h - 1][w - 1][0] + dp[h - 1][w - 1][1] + dp[h - 1][w - 1][2] + dp[h - 1][w - 1][3]) % D;
	return 0;
}