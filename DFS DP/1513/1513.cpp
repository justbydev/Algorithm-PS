/*BOJ 1513*/
/*DFS+DP*/
/*출발점과 도착점에서 값이 있다는 것이 중요*/
#include<iostream>
using namespace std;
int N, M, C, x, y;
int map[50][50];
int dp[50][50][51][51];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int dfs(int x, int y, int target, int before_num) {
	if (target < 0) {
		return 0;
	}
	if (x == N - 1 && y == M - 1) {
		if (target == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[x][y][target][before_num] != -1) {
		return dp[x][y][target][before_num];
	}
	int ret = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			continue;
		}
		if (map[nx][ny] == 0) {
			ret = (ret + dfs(nx, ny, target, before_num)) % 1000007;
		}
		else if (before_num < map[nx][ny]) {
			ret = (ret + dfs(nx, ny, target - 1, map[nx][ny])) % 1000007;
		}
	}
	return dp[x][y][target][before_num]=ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = 0;
			for (int k = 0; k <= C; k++) {
				for (int l = 0; l <= C; l++) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= C; i++) {
		cin >> x >> y;
		map[x - 1][y - 1] = i;
	}
	for (int i = 0; i <= C; i++) {
		if (map[0][0] == 0) {
			cout << dfs(0, 0, i, 0) << " ";
		}
		else {
			cout << dfs(0, 0, i - 1, map[0][0]) << " ";
		}
	}
	return 0;
}