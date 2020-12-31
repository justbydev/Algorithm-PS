/*BOJ 1949*/
/*using Tree DP*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> tree[10001];
int N;
int people[10001];
int st, ed;
int dp[10001][2];
int visit[10001];
int tree_dp(int now, int best) {
	if (dp[now][best] != -1) {
		return dp[now][best];
	}
	visit[now] = true;
	int ret = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (visit[next]) {
			continue;
		}
		if (best == 1) {
			ret += tree_dp(next, 0);
		}
		else {
			ret += max(tree_dp(next, 0), tree_dp(next, 1));
		}
	}
	visit[now] = false;
	if (best == 1) {
		ret += people[now];
	}
	return dp[now][best] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> people[i];
		dp[i][0] = dp[i][1] = -1;
		visit[i] = false;
	}
	for (int i = 1; i <= N - 1; i++) {
		cin >> st >> ed;
		tree[st].push_back(ed);
		tree[ed].push_back(st);
	}
	cout << max(tree_dp(1, 0), tree_dp(1, 1));
	return 0;
}