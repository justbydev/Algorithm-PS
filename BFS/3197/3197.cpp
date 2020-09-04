#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int R, C;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int sx, sy;
int ex, ey;
char ice[1500][1500];
queue<pair<int, int>> melt;
queue<pair<int, int>> q;
bool visit[1500][1500];
int bfs(void) {
	queue<pair<int, int>> tmp;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				continue;
			}
			if (visit[nx][ny] == 1) {
				continue;
			}
			if (nx == ex && ny == ey) {
				return 1;
			}
			if (ice[nx][ny] == 'X' || ice[nx][ny] == '*') {
				if (visit[nx][ny] == 0) {
					tmp.push({ nx, ny });
					visit[nx][ny] = 2;
				}
				continue;
			}
			if (ice[nx][ny] == '.') {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	q = tmp;
	return -1;
}
void melting(void) {
	while (1) {
		pair<int, int> now = melt.front();
		melt.pop();
		if (now.first == -1) {
			break;
		}
		ice[now.first][now.second] = '.';
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				continue;
			}
			if (ice[nx][ny] == 'X') {
				melt.push({ nx, ny });
				ice[nx][ny] = '*';
			}
		}
	}
	melt.push({ -1, -1 });
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> R >> C;
	sx = -1; ex = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> ice[i][j];
			if (ice[i][j] == 'L'&&sx == -1) {
				sx = i; sy = j;
				ice[i][j] = '.';
			}
			else if (ice[i][j] == 'L'&&ex == -1) {
				ex = i; ey = j;
				ice[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (ice[i][j] == 'X') {
				int flag = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
						continue;
					}
					if (ice[nx][ny] == '.') {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					melt.push({ i, j });
					ice[i][j] = '*';
				}
			}
		}
	}
	melt.push({ -1, -1 });
	int time = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visit[i][j] = false;
		}
	}
	visit[sx][sy] = true;
	q.push({ sx, sy });
	while (1) {
		int flag = bfs();
		if (flag == 1) {
			break;
		}
		melting();
		time++;
	}
	cout << time;
	return 0;
}