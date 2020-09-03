#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int N, post = 0;
char mp[50][50];
int tired[50][50];
int sx, sy;
vector<int> sort_tired;
int res = 1e9;
bool visit[50][50];
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int bfs(int low, int high) {
	if (tired[sx][sy]<low || tired[sx][sy]>high) {
		return -1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				continue;
			}
			if (visit[nx][ny]) {
				continue;
			}
			if (tired[nx][ny]<low || tired[nx][ny]>high) {
				continue;
			}
			visit[nx][ny] = true;
			if (mp[nx][ny] == 'K') {
				cnt++;
			}
			if (cnt == post) {
				return 1;
			}
			q.push({ nx, ny });
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'P') {
				sx = i; sy = j;
			}
			else if (mp[i][j] == 'K') {
				post++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tired[i][j];
			sort_tired.push_back(tired[i][j]);
		}
	}
	sort(sort_tired.begin(), sort_tired.end());
	int l, r;
	l = r = 0;
	while (1) {
		int flag = bfs(sort_tired[l], sort_tired[r]);
		if (flag == -1) {
			if (r != sort_tired.size() - 1) {
				r++;
			}
			else {
				break;
			}
		}
		else {
			res = min(res, sort_tired[r] - sort_tired[l]);
			if (l == r) {
				break;
			}
			else {
				l++;
			}
		}
	}
	cout << res;
	return 0;
}