#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N, a, b, M;
int anc[100001][19];
vector<int> graph[100001];
bool visit[100001];
int depth[100001];
void dfs(int now, int d) {
	depth[now] = d;
	for (int nx : graph[now]) {
		if (visit[nx]) {
			continue;
		}
		visit[nx] = true;
		anc[nx][0] = now;
		dfs(nx, d + 1);
	}
}
void cal_anc(void) {
	for (int x = 1; x <= 18; x++) {
		for (int node = 2; node <= N; node++) {
			anc[node][x] = anc[anc[node][x - 1]][x - 1];
		}
	}
}
int LCA(int a, int b) {
	int tmp;
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			tmp = a; a = b; b = tmp;
		}
		for (int i = 18; i >= 0; i--) {
			if (anc[a][i] != 0) {
				if (depth[b] <= depth[anc[a][i]]) {
					a = anc[a][i];
				}
			}
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = 18; i >= 0; i--) {
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	memset(visit, false, sizeof(visit));
	visit[1] = true;
	dfs(1, 0);
	cal_anc();
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	return 0;
}