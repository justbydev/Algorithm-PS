#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int parent[18][100001];
int mx[18][100001];
int mn[18][100001];
int depth[100001];
bool visit[100001];
int N, A, B, C, K, D, E;
int res_min, res_max;
vector<pair<int, int>> graph[100001];
void dfs_preorder(int node, int d) {
	depth[node] = d;
	for (int i = 0; i < graph[node].size(); i++) {
		int nx = graph[node][i].first;
		int len = graph[node][i].second;
		if (visit[nx]) {
			continue;
		}
		visit[nx] = true;
		parent[0][nx] = node;
		mx[0][nx] = len;
		mn[0][nx] = len;
		dfs_preorder(nx, d + 1);
	}
}
void cal(void) {
	for (int i = 1; i <= 17; i++) {
		for (int node = 2; node <= N; node++) {
			parent[i][node] = parent[i - 1][parent[i - 1][node]];
			mx[i][node] = max(mx[i - 1][node], mx[i - 1][parent[i - 1][node]]);
			mn[i][node] = min(mn[i - 1][node], mn[i - 1][parent[i - 1][node]]);
		}
	}
}
void LCA(int one, int two) {
	if (depth[one] != depth[two]) {
		if (depth[one] < depth[two]) {
			int tmp = one; one = two; two = tmp;
		}
		for (int i = 17; i >= 0; i--) {
			if (depth[parent[i][one]] >= depth[two]) {
				res_min = min(res_min, mn[i][one]);
				res_max = max(res_max, mx[i][one]);
				one = parent[i][one];
			}
		}
	}
	if (one == two) {
		return;
	}
	for (int i = 17; i >= 0; i--) {
		if (parent[i][one] != parent[i][two]) {
			res_min = min(res_min, min(mn[i][one], mn[i][two]));
			res_max = max(res_max, max(mx[i][one], mx[i][two]));
			one = parent[i][one];
			two = parent[i][two];
		}
	}
	res_min = min(res_min, min(mn[0][one], mn[0][two]));
	res_max = max(res_max, max(mx[0][one], mx[0][two]));
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({ B, C });
		graph[B].push_back({ A, C });
	}
	memset(visit, false, sizeof(bool) * 100001);
	visit[1] = true;
	for (int i = 0; i <= 17; i++) {
		for (int j = 0; j <= N; j++) {
			mx[i][j] = 0;
			mn[i][j] = 1e9;
		}
	}
	dfs_preorder(1, 0);
	cal();
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> D >> E;
		res_min = 1e9;
		res_max = 0;
		LCA(D, E);
		cout << res_min << " " << res_max << "\n";
	}
	return 0;
}