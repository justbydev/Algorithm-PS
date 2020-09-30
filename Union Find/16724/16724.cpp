#include<iostream>
using namespace std;
int N, M;
char mp[1000][1000];
bool visit[1000][1000];
int parent[1000000];
char dir[4] = { 'U', 'L', 'D', 'R' };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dfs(int x, int y) {
	if (visit[x][y]) {
		return x * M + y;
	}
	int fin;
	for (int i = 0; i < 4; i++) {
		if (mp[x][y] == dir[i]) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			visit[x][y] = true;
			fin = dfs(nx, ny);
			break;
		}
	}
	return parent[x*M + y] = fin;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < N*M; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == false) {
				dfs(i, j);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N*M; i++) {
		if (parent[i] == i) {
			res++;
		}
	}
	cout << res;
	return 0;
}