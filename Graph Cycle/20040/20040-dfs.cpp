#include<iostream>
#include<vector>
using namespace std;
int n, m, a, b;
vector<int> graph[500000];
bool visit[500000];
int dfs(int before, int now) {
	if (visit[now]) {
		return 1;
	}
	visit[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (before != next) {
			if (dfs(now, next)) {
				return 1;
			}
		}
	}
	return 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (res != 0) {
			continue;
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
		for (int j = 0; j < n; j++) {
			visit[j] = false;
		}
		if (i == 1) {
			continue;
		}
		else {
			if (dfs(-1, a)) {
				res = i;
			}
		}
	}
	cout << res;
	return 0;
}