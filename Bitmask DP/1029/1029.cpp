#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N;
char mp[15][15];
int dp[1 << 15][15][10];
int bit_dp(int state, int have, int money, int cnt) {
	if (cnt >= N) {
		return 1;
	}
	if (dp[state][have][money]) {
		return dp[state][have][money];
	}
	int ret = 1;
	for (int i = 0; i < N; i++) {
		if (i == have) {
			continue;
		}
		if ((state&(1 << i)) != 0) {
			continue;
		}
		if ((mp[have][i] - '0') < money) {
			continue;
		}
		int next_state = state | (1 << i);
		ret = max(ret, 1 + bit_dp(next_state, i, mp[have][i] - '0', cnt + 1));
	}
	return dp[state][have][money] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}
	int state = 1;
	cout << bit_dp(state, 0, 0, 1);
	return 0;
}