#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int N, P;
int cost[16][16];
int dp[1 << 16];
int bit_dp(int state, int cnt) {
	if (cnt == P) {
		return 0;
	}
	if (dp[state] != -1) {
		return dp[state];
	}
	int ret = 1e9;
	for (int i = 0; i < N; i++) {
		if ((state&(1 << i)) == 0) {
			continue;
		}
		for (int j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			if ((state&(1 << j)) != 0) {
				continue;
			}
			int next_state = state | (1 << j);
			ret = min(ret, cost[i][j] + bit_dp(next_state, cnt + 1));
		}
	}
	return dp[state] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	string now;
	cin >> now;
	int state = 0;
	int cnt = 0;
	for (int i = 0; i < now.length(); i++) {
		if (now[i] == 'Y') {
			cnt++;
			state |= (1 << i);
		}
	}
	cin >> P;
	if (cnt >= P) {
		cout << 0;
	}
	else if (cnt == 0) {
		if (P == 0) {
			cout << 0;
		}
		else {
			cout << -1;
		}
	}
	else {
		memset(dp, -1, sizeof(int)*(1 << 16));
		cout << bit_dp(state, cnt);
	}
	return 0;
}