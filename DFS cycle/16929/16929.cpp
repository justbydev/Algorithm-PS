/*BOJ 16929*/
/*detect cycle using DFS*/
#include<iostream>
using namespace std;
int N, M;
char map[50][50];
bool visit[50][50];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int dfs(int nowx, int nowy, char alpha, int bx, int by) {
	int ret = 0;
	visit[nowx][nowy] = true;
	for (int i = 0; i < 4; i++) {
		int nx = nowx + dx[i];
		int ny = nowy + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			continue;
		}
		if (map[nx][ny] != alpha) {
			continue;
		}
		if (visit[nx][ny]) {
			if (bx == nx && by == ny) {
				continue;
			}
			else {
				return 1;
			}
		}
		else {
			ret = dfs(nx, ny, alpha, nowx, nowy);
			if (ret == 1) {
				return 1;
			}
		}
	}
	return 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) {
				continue;
			}
			res = dfs(i, j, map[i][j], -1, -1);
			if (res == 1) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}