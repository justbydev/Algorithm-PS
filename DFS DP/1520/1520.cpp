/*BOJ 1520 내리막길*/
/*using DFS DP*/
#include<iostream>
using namespace std;
int M, N;
int map[500][500];
int dp[500][500];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int dfs_dp(int x, int y) {
	if (x == M - 1 && y == N - 1) {
		return 1;
	}
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	int dist = 0;
	int now_h = map[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		if (now_h <= map[nx][ny]) {
			continue;
		}
		dist += dfs_dp(nx, ny);
	}
	return dp[x][y] = dist;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs_dp(0, 0);
	return 0;
}