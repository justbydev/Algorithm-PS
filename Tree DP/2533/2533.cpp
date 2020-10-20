#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, u, v;
vector<int> tree[1000001];
int dp[1000001][2];
bool visit[1000001];
void dfs(int before, int now) {
	visit[now] = true;
	int me_early_sm = 0;
	int me_not_early_sm = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (visit[next]) {
			continue;
		}
		dfs(now, next);
		if (dp[next][0] != 1e9) {
			me_early_sm += min(dp[next][0], dp[next][1]);
		}
		me_not_early_sm += dp[next][1];
	}
	dp[now][1] = me_early_sm + 1;
	if (me_not_early_sm != 0) {
		dp[now][0] = me_not_early_sm;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
		for (int j = 0; j < 2; j++) {
			dp[i][j] = 1e9;
		}
	}
	dfs(-1, 1);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}