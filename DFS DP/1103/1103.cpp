#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
char mp[50][50];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
bool visit[50][50];
int res = 0;
int dp[50][50];
int dfs(int x, int y) {
	if (res == -1) {//무한 반복
		return -1;
	}
	if (x < 0 || x >= N || y < 0 || y >= M) {//밖으로 나가는 경우, 원하는 상태
		return 0;
	}
	if (mp[x][y] == 'H') {//구멍으로, 원하는 상태
		return 0;
	}
	if (visit[x][y]) {//dfs 경로상 같은 곳 방문->무한 반복
		res = -1;
		return -1;
	}
	if (dp[x][y]) {//이미 다른 경로를 통해 반복했던 곳
		return dp[x][y];
	}
	visit[x][y] = true;
	int ret = 0;
	for (int i = 0; i < 4; i++) {//정상적인 상하좌우 이동
		int nx = x + dx[i] * (mp[x][y] - '0');
		int ny = y + dy[i] * (mp[x][y] - '0');
		int now = dfs(nx, ny);
		if (now == -1) {
			return -1;
		}
		ret = max(ret, now);
	}
	visit[x][y] = false;
	return dp[x][y] = ret + 1;
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
	for (int i = 0; i < 50; i++) {
		memset(visit[i], false, sizeof(bool) * 50);
	}
	cout << dfs(0, 0);

	return 0;
}